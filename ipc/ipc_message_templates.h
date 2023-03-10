// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef IPC_IPC_MESSAGE_TEMPLATES_H_
#define IPC_IPC_MESSAGE_TEMPLATES_H_

#include <stdint.h>

#include <type_traits>

#include "base/logging.h"
#include "base/tuple.h"
#include "build/build_config.h"
#include "ipc/ipc_message.h"
#include "ipc/ipc_message_utils.h"

namespace IPC {

// This function is for all the async IPCs that don't pass an extra parameter
// using IPC_BEGIN_MESSAGE_MAP_WITH_PARAM.
template <typename ObjT, typename Method, typename P, typename Tuple>
void DispatchToMethod(ObjT* obj, Method method, P*, const Tuple& tuple)
{
    base::DispatchToMethod(obj, method, tuple);
}

template <typename ObjT,
    typename Method,
    typename P,
    typename Tuple,
    size_t... Ns>
void DispatchToMethodImpl(ObjT* obj,
    Method method,
    P* parameter,
    const Tuple& tuple,
    base::IndexSequence<Ns...>)
{
    // TODO(mdempsky): Apply UnwrapTraits like base::DispatchToMethod?
    (obj->*method)(parameter, base::get<Ns>(tuple)...);
}

// The following function is for async IPCs which have a dispatcher with an
// extra parameter specified using IPC_BEGIN_MESSAGE_MAP_WITH_PARAM.
template <typename ObjT, typename P, typename... Args, typename... Ts>
typename std::enable_if<sizeof...(Args) == sizeof...(Ts)>::type
DispatchToMethod(ObjT* obj,
    void (ObjT::*method)(P*, Args...),
    P* parameter,
    const base::Tuple<Ts...>& tuple)
{
    DispatchToMethodImpl(obj, method, parameter, tuple,
        base::MakeIndexSequence<sizeof...(Ts)>());
}

enum class MessageKind {
    CONTROL,
    ROUTED,
};

// Routing is a helper struct so MessageT's private common constructor has a
// different type signature than the public "int32_t routing_id" one.
struct Routing {
    explicit Routing(int32_t id)
        : id(id)
    {
    }
    int32_t id;
};

// We want to restrict MessageT's constructors so that a routing_id is always
// provided for ROUTED messages and never provided for CONTROL messages, so
// use the SFINAE technique from N4387's "Implementation Hint" section.
#if defined(COMPILER_MSVC)
// MSVC 2013 doesn't support default arguments for template member functions
// of templated classes, so there we have to rely on the DCHECKs instead.
// TODO(mdempsky): Reevaluate once MSVC 2015.
#define IPC_MESSAGET_SFINAE(x)
#else
#define IPC_MESSAGET_SFINAE(x) \
    template <bool X = (x), typename std::enable_if<X, bool>::type = false>
#endif

// MessageT is the common template used for all user-defined message types.
// It's intended to be used via the macros defined in ipc_message_macros.h.
template <typename Meta,
    typename InTuple = typename Meta::InTuple,
    typename OutTuple = typename Meta::OutTuple>
class MessageT;

// Asynchronous message partial specialization.
template <typename Meta, typename... Ins>
class MessageT<Meta, base::Tuple<Ins...>, void> : public Message {
public:
    using Param = base::Tuple<Ins...>;
    enum { ID = Meta::ID };

    // TODO(mdempsky): Remove.  Uses of MyMessage::Schema::Param can be replaced
    // with just MyMessage::Param.
    using Schema = MessageT;

    IPC_MESSAGET_SFINAE(Meta::kKind == MessageKind::CONTROL)
    MessageT(const Ins&... ins)
        : MessageT(Routing(MSG_ROUTING_CONTROL), ins...)
    {
        DCHECK(Meta::kKind == MessageKind::CONTROL) << Meta::kName;
    }

    IPC_MESSAGET_SFINAE(Meta::kKind == MessageKind::ROUTED)
    MessageT(int32_t routing_id, const Ins&... ins)
        : MessageT(Routing(routing_id), ins...)
    {
        DCHECK(Meta::kKind == MessageKind::ROUTED) << Meta::kName;
    }

    static bool Read(const Message* msg, Param* p);
    static void Log(std::string* name, const Message* msg, std::string* l);

    template <class T, class S, class P, class Method>
    static bool Dispatch(const Message* msg,
        T* obj,
        S* sender,
        P* parameter,
        Method func)
    {
        Param p;
        if (Read(msg, &p)) {
            DispatchToMethod(obj, func, parameter, p);
            return true;
        }
        return false;
    }

private:
    MessageT(Routing routing, const Ins&... ins);
};

// Synchronous message partial specialization.
template <typename Meta, typename... Ins, typename... Outs>
class MessageT<Meta, base::Tuple<Ins...>, base::Tuple<Outs...>>
    : public SyncMessage {
public:
    using SendParam = base::Tuple<Ins...>;
    using ReplyParam = base::Tuple<Outs...>;
    enum { ID = Meta::ID };

    // TODO(mdempsky): Remove.  Uses of MyMessage::Schema::{Send,Reply}Param can
    // be replaced with just MyMessage::{Send,Reply}Param.
    using Schema = MessageT;

    IPC_MESSAGET_SFINAE(Meta::kKind == MessageKind::CONTROL)
    MessageT(const Ins&... ins, Outs*... outs)
        : MessageT(Routing(MSG_ROUTING_CONTROL), ins..., outs...)
    {
        DCHECK(Meta::kKind == MessageKind::CONTROL) << Meta::kName;
    }

    IPC_MESSAGET_SFINAE(Meta::kKind == MessageKind::ROUTED)
    MessageT(int32_t routing_id, const Ins&... ins, Outs*... outs)
        : MessageT(Routing(routing_id), ins..., outs...)
    {
        DCHECK(Meta::kKind == MessageKind::ROUTED) << Meta::kName;
    }

    static bool ReadSendParam(const Message* msg, SendParam* p);
    static bool ReadReplyParam(const Message* msg, ReplyParam* p);
    static void WriteReplyParams(Message* reply, const Outs&... outs);
    static void Log(std::string* name, const Message* msg, std::string* l);

    template <class T, class S, class P, class Method>
    static bool Dispatch(const Message* msg,
        T* obj,
        S* sender,
        P* parameter,
        Method func)
    {
        SendParam send_params;
        bool ok = ReadSendParam(msg, &send_params);
        Message* reply = SyncMessage::GenerateReply(msg);
        if (ok) {
            ReplyParam reply_params;
            base::DispatchToMethod(obj, func, send_params, &reply_params);
            WriteParam(reply, reply_params);
            LogReplyParamsToMessage(reply_params, msg);
        } else {
            NOTREACHED() << "Error deserializing message " << msg->type();
            reply->set_reply_error();
        }
        sender->Send(reply);
        return ok;
    }

    template <class T, class P, class Method>
    static bool DispatchDelayReply(const Message* msg,
        T* obj,
        P* parameter,
        Method func)
    {
        SendParam send_params;
        bool ok = ReadSendParam(msg, &send_params);
        Message* reply = SyncMessage::GenerateReply(msg);
        if (ok) {
            base::Tuple<Message&> t = base::MakeRefTuple(*reply);
            ConnectMessageAndReply(msg, reply);
            base::DispatchToMethod(obj, func, send_params, &t);
        } else {
            NOTREACHED() << "Error deserializing message " << msg->type();
            reply->set_reply_error();
            obj->Send(reply);
        }
        return ok;
    }

private:
    MessageT(Routing routing, const Ins&... ins, Outs*... outs);
};

} // namespace IPC

#if defined(IPC_MESSAGE_IMPL)
#include "ipc/ipc_message_templates_impl.h"
#endif

#endif // IPC_IPC_MESSAGE_TEMPLATES_H_
