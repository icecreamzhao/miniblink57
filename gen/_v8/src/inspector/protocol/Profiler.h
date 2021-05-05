// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef v8_inspector_protocol_Profiler_h
#define v8_inspector_protocol_Profiler_h

#include "src/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.
#include "src/inspector/protocol/Debugger.h"
#include "src/inspector/protocol/Runtime.h"

namespace v8_inspector {
namespace protocol {
    namespace Profiler {

        // ------------- Forward and enum declarations.
        // Profile node. Holds callsite information, execution statistics and child nodes.
        class ProfileNode;
        // Profile.
        class Profile;
        // Specifies a number of samples attributed to a certain source position.
        class PositionTickInfo;
        // Wrapper for notification params
        class ConsoleProfileStartedNotification;
        // Wrapper for notification params
        class ConsoleProfileFinishedNotification;

        // ------------- Type and builder declarations.

        // Profile node. Holds callsite information, execution statistics and child nodes.
        class ProfileNode : public Serializable {
            PROTOCOL_DISALLOW_COPY(ProfileNode);

        public:
            static std::unique_ptr<ProfileNode> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ProfileNode() override { }

            int getId() { return m_id; }
            void setId(int value) { m_id = value; }

            protocol::Runtime::CallFrame* getCallFrame() { return m_callFrame.get(); }
            void setCallFrame(std::unique_ptr<protocol::Runtime::CallFrame> value) { m_callFrame = std::move(value); }

            bool hasHitCount() { return m_hitCount.isJust(); }
            int getHitCount(int defaultValue) { return m_hitCount.isJust() ? m_hitCount.fromJust() : defaultValue; }
            void setHitCount(int value) { m_hitCount = value; }

            bool hasChildren() { return m_children.isJust(); }
            protocol::Array<int>* getChildren(protocol::Array<int>* defaultValue) { return m_children.isJust() ? m_children.fromJust() : defaultValue; }
            void setChildren(std::unique_ptr<protocol::Array<int>> value) { m_children = std::move(value); }

            bool hasDeoptReason() { return m_deoptReason.isJust(); }
            String getDeoptReason(const String& defaultValue) { return m_deoptReason.isJust() ? m_deoptReason.fromJust() : defaultValue; }
            void setDeoptReason(const String& value) { m_deoptReason = value; }

            bool hasPositionTicks() { return m_positionTicks.isJust(); }
            protocol::Array<protocol::Profiler::PositionTickInfo>* getPositionTicks(protocol::Array<protocol::Profiler::PositionTickInfo>* defaultValue) { return m_positionTicks.isJust() ? m_positionTicks.fromJust() : defaultValue; }
            void setPositionTicks(std::unique_ptr<protocol::Array<protocol::Profiler::PositionTickInfo>> value) { m_positionTicks = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ProfileNode> clone() const;

            template <int STATE>
            class ProfileNodeBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    IdSet = 1 << 1,
                    CallFrameSet = 1 << 2,
                    AllFieldsSet = (IdSet | CallFrameSet | 0)
                };

                ProfileNodeBuilder<STATE | IdSet>& setId(int value)
                {
                    static_assert(!(STATE & IdSet), "property id should not be set yet");
                    m_result->setId(value);
                    return castState<IdSet>();
                }

                ProfileNodeBuilder<STATE | CallFrameSet>& setCallFrame(std::unique_ptr<protocol::Runtime::CallFrame> value)
                {
                    static_assert(!(STATE & CallFrameSet), "property callFrame should not be set yet");
                    m_result->setCallFrame(std::move(value));
                    return castState<CallFrameSet>();
                }

                ProfileNodeBuilder<STATE>& setHitCount(int value)
                {
                    m_result->setHitCount(value);
                    return *this;
                }

                ProfileNodeBuilder<STATE>& setChildren(std::unique_ptr<protocol::Array<int>> value)
                {
                    m_result->setChildren(std::move(value));
                    return *this;
                }

                ProfileNodeBuilder<STATE>& setDeoptReason(const String& value)
                {
                    m_result->setDeoptReason(value);
                    return *this;
                }

                ProfileNodeBuilder<STATE>& setPositionTicks(std::unique_ptr<protocol::Array<protocol::Profiler::PositionTickInfo>> value)
                {
                    m_result->setPositionTicks(std::move(value));
                    return *this;
                }

                std::unique_ptr<ProfileNode> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ProfileNode;
                ProfileNodeBuilder()
                    : m_result(new ProfileNode())
                {
                }

                template <int STEP>
                ProfileNodeBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ProfileNodeBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Profiler::ProfileNode> m_result;
            };

            static ProfileNodeBuilder<0> create()
            {
                return ProfileNodeBuilder<0>();
            }

        private:
            ProfileNode()
            {
                m_id = 0;
            }

            int m_id;
            std::unique_ptr<protocol::Runtime::CallFrame> m_callFrame;
            Maybe<int> m_hitCount;
            Maybe<protocol::Array<int>> m_children;
            Maybe<String> m_deoptReason;
            Maybe<protocol::Array<protocol::Profiler::PositionTickInfo>> m_positionTicks;
        };

        // Profile.
        class Profile : public Serializable {
            PROTOCOL_DISALLOW_COPY(Profile);

        public:
            static std::unique_ptr<Profile> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~Profile() override { }

            protocol::Array<protocol::Profiler::ProfileNode>* getNodes() { return m_nodes.get(); }
            void setNodes(std::unique_ptr<protocol::Array<protocol::Profiler::ProfileNode>> value) { m_nodes = std::move(value); }

            double getStartTime() { return m_startTime; }
            void setStartTime(double value) { m_startTime = value; }

            double getEndTime() { return m_endTime; }
            void setEndTime(double value) { m_endTime = value; }

            bool hasSamples() { return m_samples.isJust(); }
            protocol::Array<int>* getSamples(protocol::Array<int>* defaultValue) { return m_samples.isJust() ? m_samples.fromJust() : defaultValue; }
            void setSamples(std::unique_ptr<protocol::Array<int>> value) { m_samples = std::move(value); }

            bool hasTimeDeltas() { return m_timeDeltas.isJust(); }
            protocol::Array<int>* getTimeDeltas(protocol::Array<int>* defaultValue) { return m_timeDeltas.isJust() ? m_timeDeltas.fromJust() : defaultValue; }
            void setTimeDeltas(std::unique_ptr<protocol::Array<int>> value) { m_timeDeltas = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<Profile> clone() const;

            template <int STATE>
            class ProfileBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    NodesSet = 1 << 1,
                    StartTimeSet = 1 << 2,
                    EndTimeSet = 1 << 3,
                    AllFieldsSet = (NodesSet | StartTimeSet | EndTimeSet | 0)
                };

                ProfileBuilder<STATE | NodesSet>& setNodes(std::unique_ptr<protocol::Array<protocol::Profiler::ProfileNode>> value)
                {
                    static_assert(!(STATE & NodesSet), "property nodes should not be set yet");
                    m_result->setNodes(std::move(value));
                    return castState<NodesSet>();
                }

                ProfileBuilder<STATE | StartTimeSet>& setStartTime(double value)
                {
                    static_assert(!(STATE & StartTimeSet), "property startTime should not be set yet");
                    m_result->setStartTime(value);
                    return castState<StartTimeSet>();
                }

                ProfileBuilder<STATE | EndTimeSet>& setEndTime(double value)
                {
                    static_assert(!(STATE & EndTimeSet), "property endTime should not be set yet");
                    m_result->setEndTime(value);
                    return castState<EndTimeSet>();
                }

                ProfileBuilder<STATE>& setSamples(std::unique_ptr<protocol::Array<int>> value)
                {
                    m_result->setSamples(std::move(value));
                    return *this;
                }

                ProfileBuilder<STATE>& setTimeDeltas(std::unique_ptr<protocol::Array<int>> value)
                {
                    m_result->setTimeDeltas(std::move(value));
                    return *this;
                }

                std::unique_ptr<Profile> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class Profile;
                ProfileBuilder()
                    : m_result(new Profile())
                {
                }

                template <int STEP>
                ProfileBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ProfileBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Profiler::Profile> m_result;
            };

            static ProfileBuilder<0> create()
            {
                return ProfileBuilder<0>();
            }

        private:
            Profile()
            {
                m_startTime = 0;
                m_endTime = 0;
            }

            std::unique_ptr<protocol::Array<protocol::Profiler::ProfileNode>> m_nodes;
            double m_startTime;
            double m_endTime;
            Maybe<protocol::Array<int>> m_samples;
            Maybe<protocol::Array<int>> m_timeDeltas;
        };

        // Specifies a number of samples attributed to a certain source position.
        class PositionTickInfo : public Serializable {
            PROTOCOL_DISALLOW_COPY(PositionTickInfo);

        public:
            static std::unique_ptr<PositionTickInfo> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~PositionTickInfo() override { }

            int getLine() { return m_line; }
            void setLine(int value) { m_line = value; }

            int getTicks() { return m_ticks; }
            void setTicks(int value) { m_ticks = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<PositionTickInfo> clone() const;

            template <int STATE>
            class PositionTickInfoBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    LineSet = 1 << 1,
                    TicksSet = 1 << 2,
                    AllFieldsSet = (LineSet | TicksSet | 0)
                };

                PositionTickInfoBuilder<STATE | LineSet>& setLine(int value)
                {
                    static_assert(!(STATE & LineSet), "property line should not be set yet");
                    m_result->setLine(value);
                    return castState<LineSet>();
                }

                PositionTickInfoBuilder<STATE | TicksSet>& setTicks(int value)
                {
                    static_assert(!(STATE & TicksSet), "property ticks should not be set yet");
                    m_result->setTicks(value);
                    return castState<TicksSet>();
                }

                std::unique_ptr<PositionTickInfo> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class PositionTickInfo;
                PositionTickInfoBuilder()
                    : m_result(new PositionTickInfo())
                {
                }

                template <int STEP>
                PositionTickInfoBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<PositionTickInfoBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Profiler::PositionTickInfo> m_result;
            };

            static PositionTickInfoBuilder<0> create()
            {
                return PositionTickInfoBuilder<0>();
            }

        private:
            PositionTickInfo()
            {
                m_line = 0;
                m_ticks = 0;
            }

            int m_line;
            int m_ticks;
        };

        // Wrapper for notification params
        class ConsoleProfileStartedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(ConsoleProfileStartedNotification);

        public:
            static std::unique_ptr<ConsoleProfileStartedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ConsoleProfileStartedNotification() override { }

            String getId() { return m_id; }
            void setId(const String& value) { m_id = value; }

            protocol::Debugger::Location* getLocation() { return m_location.get(); }
            void setLocation(std::unique_ptr<protocol::Debugger::Location> value) { m_location = std::move(value); }

            bool hasTitle() { return m_title.isJust(); }
            String getTitle(const String& defaultValue) { return m_title.isJust() ? m_title.fromJust() : defaultValue; }
            void setTitle(const String& value) { m_title = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ConsoleProfileStartedNotification> clone() const;

            template <int STATE>
            class ConsoleProfileStartedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    IdSet = 1 << 1,
                    LocationSet = 1 << 2,
                    AllFieldsSet = (IdSet | LocationSet | 0)
                };

                ConsoleProfileStartedNotificationBuilder<STATE | IdSet>& setId(const String& value)
                {
                    static_assert(!(STATE & IdSet), "property id should not be set yet");
                    m_result->setId(value);
                    return castState<IdSet>();
                }

                ConsoleProfileStartedNotificationBuilder<STATE | LocationSet>& setLocation(std::unique_ptr<protocol::Debugger::Location> value)
                {
                    static_assert(!(STATE & LocationSet), "property location should not be set yet");
                    m_result->setLocation(std::move(value));
                    return castState<LocationSet>();
                }

                ConsoleProfileStartedNotificationBuilder<STATE>& setTitle(const String& value)
                {
                    m_result->setTitle(value);
                    return *this;
                }

                std::unique_ptr<ConsoleProfileStartedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ConsoleProfileStartedNotification;
                ConsoleProfileStartedNotificationBuilder()
                    : m_result(new ConsoleProfileStartedNotification())
                {
                }

                template <int STEP>
                ConsoleProfileStartedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ConsoleProfileStartedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Profiler::ConsoleProfileStartedNotification> m_result;
            };

            static ConsoleProfileStartedNotificationBuilder<0> create()
            {
                return ConsoleProfileStartedNotificationBuilder<0>();
            }

        private:
            ConsoleProfileStartedNotification()
            {
            }

            String m_id;
            std::unique_ptr<protocol::Debugger::Location> m_location;
            Maybe<String> m_title;
        };

        // Wrapper for notification params
        class ConsoleProfileFinishedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(ConsoleProfileFinishedNotification);

        public:
            static std::unique_ptr<ConsoleProfileFinishedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ConsoleProfileFinishedNotification() override { }

            String getId() { return m_id; }
            void setId(const String& value) { m_id = value; }

            protocol::Debugger::Location* getLocation() { return m_location.get(); }
            void setLocation(std::unique_ptr<protocol::Debugger::Location> value) { m_location = std::move(value); }

            protocol::Profiler::Profile* getProfile() { return m_profile.get(); }
            void setProfile(std::unique_ptr<protocol::Profiler::Profile> value) { m_profile = std::move(value); }

            bool hasTitle() { return m_title.isJust(); }
            String getTitle(const String& defaultValue) { return m_title.isJust() ? m_title.fromJust() : defaultValue; }
            void setTitle(const String& value) { m_title = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ConsoleProfileFinishedNotification> clone() const;

            template <int STATE>
            class ConsoleProfileFinishedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    IdSet = 1 << 1,
                    LocationSet = 1 << 2,
                    ProfileSet = 1 << 3,
                    AllFieldsSet = (IdSet | LocationSet | ProfileSet | 0)
                };

                ConsoleProfileFinishedNotificationBuilder<STATE | IdSet>& setId(const String& value)
                {
                    static_assert(!(STATE & IdSet), "property id should not be set yet");
                    m_result->setId(value);
                    return castState<IdSet>();
                }

                ConsoleProfileFinishedNotificationBuilder<STATE | LocationSet>& setLocation(std::unique_ptr<protocol::Debugger::Location> value)
                {
                    static_assert(!(STATE & LocationSet), "property location should not be set yet");
                    m_result->setLocation(std::move(value));
                    return castState<LocationSet>();
                }

                ConsoleProfileFinishedNotificationBuilder<STATE | ProfileSet>& setProfile(std::unique_ptr<protocol::Profiler::Profile> value)
                {
                    static_assert(!(STATE & ProfileSet), "property profile should not be set yet");
                    m_result->setProfile(std::move(value));
                    return castState<ProfileSet>();
                }

                ConsoleProfileFinishedNotificationBuilder<STATE>& setTitle(const String& value)
                {
                    m_result->setTitle(value);
                    return *this;
                }

                std::unique_ptr<ConsoleProfileFinishedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ConsoleProfileFinishedNotification;
                ConsoleProfileFinishedNotificationBuilder()
                    : m_result(new ConsoleProfileFinishedNotification())
                {
                }

                template <int STEP>
                ConsoleProfileFinishedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ConsoleProfileFinishedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Profiler::ConsoleProfileFinishedNotification> m_result;
            };

            static ConsoleProfileFinishedNotificationBuilder<0> create()
            {
                return ConsoleProfileFinishedNotificationBuilder<0>();
            }

        private:
            ConsoleProfileFinishedNotification()
            {
            }

            String m_id;
            std::unique_ptr<protocol::Debugger::Location> m_location;
            std::unique_ptr<protocol::Profiler::Profile> m_profile;
            Maybe<String> m_title;
        };

        // ------------- Backend interface.

        class Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse enable() = 0;
            virtual DispatchResponse disable() = 0;
            virtual DispatchResponse setSamplingInterval(int in_interval) = 0;
            virtual DispatchResponse start() = 0;
            virtual DispatchResponse stop(std::unique_ptr<protocol::Profiler::Profile>* out_profile) = 0;
        };

        // ------------- Frontend interface.

        class Frontend {
        public:
            explicit Frontend(FrontendChannel* frontendChannel)
                : m_frontendChannel(frontendChannel)
            {
            }
            void consoleProfileStarted(const String& id, std::unique_ptr<protocol::Debugger::Location> location, Maybe<String> title = Maybe<String>());
            void consoleProfileFinished(const String& id, std::unique_ptr<protocol::Debugger::Location> location, std::unique_ptr<protocol::Profiler::Profile> profile, Maybe<String> title = Maybe<String>());

            void flush();
            void sendRawNotification(const String&);

        private:
            FrontendChannel* m_frontendChannel;
        };

        // ------------- Dispatcher.

        class Dispatcher {
        public:
            static void wire(UberDispatcher*, Backend*);

        private:
            Dispatcher() { }
        };

        // ------------- Metainfo.

        class Metainfo {
        public:
            using BackendClass = Backend;
            using FrontendClass = Frontend;
            using DispatcherClass = Dispatcher;
            static const char domainName[];
            static const char commandPrefix[];
            static const char version[];
        };

    } // namespace Profiler
} // namespace v8_inspector
} // namespace protocol

#endif // !defined(v8_inspector_protocol_Profiler_h)
