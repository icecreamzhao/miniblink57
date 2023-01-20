// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/webmidi/MIDIAccessInitializer.h"

#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "core/dom/DOMException.h"
#include "core/dom/Document.h"
#include "core/dom/ExceptionCode.h"
<<<<<<< HEAD
#include "core/frame/LocalFrame.h"
#include "core/frame/Navigator.h"
#include "modules/permissions/PermissionUtils.h"
#include "modules/webmidi/MIDIAccess.h"
#include "modules/webmidi/MIDIOptions.h"
#include "modules/webmidi/MIDIPort.h"
#include "platform/UserGestureIndicator.h"
#include "platform/mojo/MojoHelper.h"
#include "public/platform/InterfaceProvider.h"
#include "public/platform/modules/permissions/permission.mojom-blink.h"

namespace blink {

using midi::mojom::PortState;
using midi::mojom::Result;
using mojom::blink::PermissionStatus;

MIDIAccessInitializer::MIDIAccessInitializer(ScriptState* scriptState,
    const MIDIOptions& options)
    : ScriptPromiseResolver(scriptState)
    , m_options(options)
{
}

void MIDIAccessInitializer::contextDestroyed(ExecutionContext*)
{
    m_permissionService.reset();
=======
#include "core/frame/Navigator.h"
#include "modules/webmidi/MIDIAccess.h"
#include "modules/webmidi/MIDIController.h"
#include "modules/webmidi/MIDIOptions.h"
#include "modules/webmidi/MIDIPort.h"

namespace blink {

using PortState = WebMIDIAccessorClient::MIDIPortState;

MIDIAccessInitializer::MIDIAccessInitializer(ScriptState* scriptState, const MIDIOptions& options)
    : ScriptPromiseResolver(scriptState)
    , m_requestSysex(false)
    , m_hasBeenDisposed(false)
    , m_sysexPermissionResolved(false)
{
    if (options.hasSysex())
        m_requestSysex = options.sysex();
}

MIDIAccessInitializer::~MIDIAccessInitializer()
{
    dispose();
}

void MIDIAccessInitializer::contextDestroyed()
{
    dispose();
    LifecycleObserver::contextDestroyed();
}

void MIDIAccessInitializer::dispose()
{
    if (m_hasBeenDisposed)
        return;

    if (!executionContext())
        return;

    if (!m_sysexPermissionResolved) {
        Document* document = toDocument(executionContext());
        ASSERT(document);
        if (MIDIController* controller = MIDIController::from(document->frame()))
            controller->cancelSysexPermissionRequest(this);
        m_sysexPermissionResolved = true;
    }

    m_hasBeenDisposed = true;
>>>>>>> miniblink49
}

ScriptPromise MIDIAccessInitializer::start()
{
    ScriptPromise promise = this->promise();
    m_accessor = MIDIAccessor::create(this);

<<<<<<< HEAD
    connectToPermissionService(getExecutionContext(),
        mojo::MakeRequest(&m_permissionService));
    m_permissionService->RequestPermission(
        createMidiPermissionDescriptor(m_options.hasSysex() && m_options.sysex()),
        getExecutionContext()->getSecurityOrigin(),
        UserGestureIndicator::processingUserGesture(),
        convertToBaseCallback(WTF::bind(
            &MIDIAccessInitializer::onPermissionsUpdated, wrapPersistent(this))));
=======
    if (!m_requestSysex) {
        m_accessor->startSession();
        return promise;
    }
    Document* document = toDocument(executionContext());
    ASSERT(document);
    if (MIDIController* controller = MIDIController::from(document->frame()))
        controller->requestSysexPermission(this);
    else
        reject(DOMException::create(SecurityError));
>>>>>>> miniblink49

    return promise;
}

<<<<<<< HEAD
void MIDIAccessInitializer::didAddInputPort(const String& id,
    const String& manufacturer,
    const String& name,
    const String& version,
    PortState state)
{
    DCHECK(m_accessor);
    m_portDescriptors.push_back(PortDescriptor(
        id, manufacturer, name, MIDIPort::TypeInput, version, state));
}

void MIDIAccessInitializer::didAddOutputPort(const String& id,
    const String& manufacturer,
    const String& name,
    const String& version,
    PortState state)
{
    DCHECK(m_accessor);
    m_portDescriptors.push_back(PortDescriptor(
        id, manufacturer, name, MIDIPort::TypeOutput, version, state));
}

void MIDIAccessInitializer::didSetInputPortState(unsigned portIndex,
    PortState state)
=======
void MIDIAccessInitializer::didAddInputPort(const String& id, const String& manufacturer, const String& name, const String& version, PortState state)
{
    ASSERT(m_accessor);
    m_portDescriptors.append(PortDescriptor(id, manufacturer, name, MIDIPort::TypeInput, version, state));
}

void MIDIAccessInitializer::didAddOutputPort(const String& id, const String& manufacturer, const String& name, const String& version, PortState state)
{
    ASSERT(m_accessor);
    m_portDescriptors.append(PortDescriptor(id, manufacturer, name, MIDIPort::TypeOutput, version, state));
}

void MIDIAccessInitializer::didSetInputPortState(unsigned portIndex, PortState state)
>>>>>>> miniblink49
{
    // didSetInputPortState() is not allowed to call before didStartSession()
    // is called. Once didStartSession() is called, MIDIAccessorClient methods
    // are delegated to MIDIAccess. See constructor of MIDIAccess.
<<<<<<< HEAD
    NOTREACHED();
}

void MIDIAccessInitializer::didSetOutputPortState(unsigned portIndex,
    PortState state)
{
    // See comments on didSetInputPortState().
    NOTREACHED();
}

void MIDIAccessInitializer::didStartSession(Result result)
{
    DCHECK(m_accessor);
    // We would also have AbortError and SecurityError according to the spec.
    // SecurityError is handled in onPermission(s)Updated().
    switch (result) {
    case Result::NOT_INITIALIZED:
        break;
    case Result::OK:
        return resolve(MIDIAccess::create(
            std::move(m_accessor), m_options.hasSysex() && m_options.sysex(),
            m_portDescriptors, getExecutionContext()));
    case Result::NOT_SUPPORTED:
        return reject(DOMException::create(NotSupportedError));
    case Result::INITIALIZATION_ERROR:
        return reject(DOMException::create(
            InvalidStateError, "Platform dependent initialization failed."));
    }
    NOTREACHED();
    reject(DOMException::create(InvalidStateError,
        "Unknown internal error occurred."));
}

ExecutionContext* MIDIAccessInitializer::getExecutionContext() const
{
    return getScriptState()->getExecutionContext();
}

void MIDIAccessInitializer::onPermissionsUpdated(PermissionStatus status)
{
    m_permissionService.reset();
    if (status == PermissionStatus::GRANTED)
=======
    ASSERT_NOT_REACHED();
}

void MIDIAccessInitializer::didSetOutputPortState(unsigned portIndex, PortState state)
{
    // See comments on didSetInputPortState().
    ASSERT_NOT_REACHED();
}

void MIDIAccessInitializer::didStartSession(bool success, const String& error, const String& message)
{
    ASSERT(m_accessor);
    if (success) {
        resolve(MIDIAccess::create(m_accessor.release(), m_requestSysex, m_portDescriptors, executionContext()));
    } else {
        // The spec says the name is one of
        //  - SecurityError
        //  - AbortError
        //  - InvalidStateError
        //  - NotSupportedError
        // TODO(toyoshim): Do not rely on |error| string. Instead an enum
        // representing an ExceptionCode should be defined and deliverred.
        ExceptionCode ec = InvalidStateError;
        if (error == DOMException::getErrorName(SecurityError)) {
            ec = SecurityError;
        } else if (error == DOMException::getErrorName(AbortError)) {
            ec = AbortError;
        } else if (error == DOMException::getErrorName(InvalidStateError)) {
            ec = InvalidStateError;
        } else if (error == DOMException::getErrorName(NotSupportedError)) {
            ec = NotSupportedError;
        }
        reject(DOMException::create(ec, message));
    }
}

void MIDIAccessInitializer::resolveSysexPermission(bool allowed)
{
    m_sysexPermissionResolved = true;
    if (allowed)
>>>>>>> miniblink49
        m_accessor->startSession();
    else
        reject(DOMException::create(SecurityError));
}

<<<<<<< HEAD
void MIDIAccessInitializer::onPermissionUpdated(PermissionStatus status)
{
    m_permissionService.reset();
    if (status == PermissionStatus::GRANTED)
        m_accessor->startSession();
    else
        reject(DOMException::create(SecurityError));
=======
SecurityOrigin* MIDIAccessInitializer::securityOrigin() const
{
    return executionContext()->securityOrigin();
}

ExecutionContext* MIDIAccessInitializer::executionContext() const
{
    return scriptState()->executionContext();
>>>>>>> miniblink49
}

} // namespace blink
