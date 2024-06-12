// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_Animation_h
#define blink_protocol_Animation_h

#include "core/CoreExport.h"
#include "core/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.
#include "core/inspector/protocol/DOM.h"
#include "core/inspector/protocol/Runtime.h"

namespace blink {
namespace protocol {
    namespace Animation {

        // ------------- Forward and enum declarations.
        // Animation instance.
        class Animation;
        // AnimationEffect instance
        class AnimationEffect;
        // Keyframes Rule
        class KeyframesRule;
        // Keyframe Style
        class KeyframeStyle;
        // Wrapper for notification params
        class AnimationCreatedNotification;
        // Wrapper for notification params
        class AnimationStartedNotification;
        // Wrapper for notification params
        class AnimationCanceledNotification;

        // ------------- Type and builder declarations.

        // Animation instance.
        class CORE_EXPORT Animation : public Serializable {
            PROTOCOL_DISALLOW_COPY(Animation);

        public:
            static std::unique_ptr<Animation> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~Animation() override { }

            String getId() { return m_id; }
            void setId(const String& value) { m_id = value; }

            String getName() { return m_name; }
            void setName(const String& value) { m_name = value; }

            bool getPausedState() { return m_pausedState; }
            void setPausedState(bool value) { m_pausedState = value; }

            String getPlayState() { return m_playState; }
            void setPlayState(const String& value) { m_playState = value; }

            double getPlaybackRate() { return m_playbackRate; }
            void setPlaybackRate(double value) { m_playbackRate = value; }

            double getStartTime() { return m_startTime; }
            void setStartTime(double value) { m_startTime = value; }

            double getCurrentTime() { return m_currentTime; }
            void setCurrentTime(double value) { m_currentTime = value; }

            protocol::Animation::AnimationEffect* getSource() { return m_source.get(); }
            void setSource(std::unique_ptr<protocol::Animation::AnimationEffect> value) { m_source = std::move(value); }

            struct CORE_EXPORT TypeEnum {
                static const char* CSSTransition;
                static const char* CSSAnimation;
                static const char* WebAnimation;
            }; // TypeEnum

            String getType() { return m_type; }
            void setType(const String& value) { m_type = value; }

            bool hasCssId() { return m_cssId.isJust(); }
            String getCssId(const String& defaultValue) { return m_cssId.isJust() ? m_cssId.fromJust() : defaultValue; }
            void setCssId(const String& value) { m_cssId = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<Animation> clone() const;

            template <int STATE>
            class AnimationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    IdSet = 1 << 1,
                    NameSet = 1 << 2,
                    PausedStateSet = 1 << 3,
                    PlayStateSet = 1 << 4,
                    PlaybackRateSet = 1 << 5,
                    StartTimeSet = 1 << 6,
                    CurrentTimeSet = 1 << 7,
                    SourceSet = 1 << 8,
                    TypeSet = 1 << 9,
                    AllFieldsSet = (IdSet | NameSet | PausedStateSet | PlayStateSet | PlaybackRateSet | StartTimeSet | CurrentTimeSet | SourceSet | TypeSet | 0)
                };

                AnimationBuilder<STATE | IdSet>& setId(const String& value)
                {
                    static_assert(!(STATE & IdSet), "property id should not be set yet");
                    m_result->setId(value);
                    return castState<IdSet>();
                }

                AnimationBuilder<STATE | NameSet>& setName(const String& value)
                {
                    static_assert(!(STATE & NameSet), "property name should not be set yet");
                    m_result->setName(value);
                    return castState<NameSet>();
                }

                AnimationBuilder<STATE | PausedStateSet>& setPausedState(bool value)
                {
                    static_assert(!(STATE & PausedStateSet), "property pausedState should not be set yet");
                    m_result->setPausedState(value);
                    return castState<PausedStateSet>();
                }

                AnimationBuilder<STATE | PlayStateSet>& setPlayState(const String& value)
                {
                    static_assert(!(STATE & PlayStateSet), "property playState should not be set yet");
                    m_result->setPlayState(value);
                    return castState<PlayStateSet>();
                }

                AnimationBuilder<STATE | PlaybackRateSet>& setPlaybackRate(double value)
                {
                    static_assert(!(STATE & PlaybackRateSet), "property playbackRate should not be set yet");
                    m_result->setPlaybackRate(value);
                    return castState<PlaybackRateSet>();
                }

                AnimationBuilder<STATE | StartTimeSet>& setStartTime(double value)
                {
                    static_assert(!(STATE & StartTimeSet), "property startTime should not be set yet");
                    m_result->setStartTime(value);
                    return castState<StartTimeSet>();
                }

                AnimationBuilder<STATE | CurrentTimeSet>& setCurrentTime(double value)
                {
                    static_assert(!(STATE & CurrentTimeSet), "property currentTime should not be set yet");
                    m_result->setCurrentTime(value);
                    return castState<CurrentTimeSet>();
                }

                AnimationBuilder<STATE | SourceSet>& setSource(std::unique_ptr<protocol::Animation::AnimationEffect> value)
                {
                    static_assert(!(STATE & SourceSet), "property source should not be set yet");
                    m_result->setSource(std::move(value));
                    return castState<SourceSet>();
                }

                AnimationBuilder<STATE | TypeSet>& setType(const String& value)
                {
                    static_assert(!(STATE & TypeSet), "property type should not be set yet");
                    m_result->setType(value);
                    return castState<TypeSet>();
                }

                AnimationBuilder<STATE>& setCssId(const String& value)
                {
                    m_result->setCssId(value);
                    return *this;
                }

                std::unique_ptr<Animation> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class Animation;
                AnimationBuilder()
                    : m_result(new Animation())
                {
                }

                template <int STEP>
                AnimationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<AnimationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Animation::Animation> m_result;
            };

            static AnimationBuilder<0> create()
            {
                return AnimationBuilder<0>();
            }

        private:
            Animation()
            {
                m_pausedState = false;
                m_playbackRate = 0;
                m_startTime = 0;
                m_currentTime = 0;
            }

            String m_id;
            String m_name;
            bool m_pausedState;
            String m_playState;
            double m_playbackRate;
            double m_startTime;
            double m_currentTime;
            std::unique_ptr<protocol::Animation::AnimationEffect> m_source;
            String m_type;
            Maybe<String> m_cssId;
        };

        // AnimationEffect instance
        class CORE_EXPORT AnimationEffect : public Serializable {
            PROTOCOL_DISALLOW_COPY(AnimationEffect);

        public:
            static std::unique_ptr<AnimationEffect> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~AnimationEffect() override { }

            double getDelay() { return m_delay; }
            void setDelay(double value) { m_delay = value; }

            double getEndDelay() { return m_endDelay; }
            void setEndDelay(double value) { m_endDelay = value; }

            double getIterationStart() { return m_iterationStart; }
            void setIterationStart(double value) { m_iterationStart = value; }

            double getIterations() { return m_iterations; }
            void setIterations(double value) { m_iterations = value; }

            double getDuration() { return m_duration; }
            void setDuration(double value) { m_duration = value; }

            String getDirection() { return m_direction; }
            void setDirection(const String& value) { m_direction = value; }

            String getFill() { return m_fill; }
            void setFill(const String& value) { m_fill = value; }

            int getBackendNodeId() { return m_backendNodeId; }
            void setBackendNodeId(int value) { m_backendNodeId = value; }

            bool hasKeyframesRule() { return m_keyframesRule.isJust(); }
            protocol::Animation::KeyframesRule* getKeyframesRule(protocol::Animation::KeyframesRule* defaultValue) { return m_keyframesRule.isJust() ? m_keyframesRule.fromJust() : defaultValue; }
            void setKeyframesRule(std::unique_ptr<protocol::Animation::KeyframesRule> value) { m_keyframesRule = std::move(value); }

            String getEasing() { return m_easing; }
            void setEasing(const String& value) { m_easing = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<AnimationEffect> clone() const;

            template <int STATE>
            class AnimationEffectBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    DelaySet = 1 << 1,
                    EndDelaySet = 1 << 2,
                    IterationStartSet = 1 << 3,
                    IterationsSet = 1 << 4,
                    DurationSet = 1 << 5,
                    DirectionSet = 1 << 6,
                    FillSet = 1 << 7,
                    BackendNodeIdSet = 1 << 8,
                    EasingSet = 1 << 9,
                    AllFieldsSet = (DelaySet | EndDelaySet | IterationStartSet | IterationsSet | DurationSet | DirectionSet | FillSet | BackendNodeIdSet | EasingSet | 0)
                };

                AnimationEffectBuilder<STATE | DelaySet>& setDelay(double value)
                {
                    static_assert(!(STATE & DelaySet), "property delay should not be set yet");
                    m_result->setDelay(value);
                    return castState<DelaySet>();
                }

                AnimationEffectBuilder<STATE | EndDelaySet>& setEndDelay(double value)
                {
                    static_assert(!(STATE & EndDelaySet), "property endDelay should not be set yet");
                    m_result->setEndDelay(value);
                    return castState<EndDelaySet>();
                }

                AnimationEffectBuilder<STATE | IterationStartSet>& setIterationStart(double value)
                {
                    static_assert(!(STATE & IterationStartSet), "property iterationStart should not be set yet");
                    m_result->setIterationStart(value);
                    return castState<IterationStartSet>();
                }

                AnimationEffectBuilder<STATE | IterationsSet>& setIterations(double value)
                {
                    static_assert(!(STATE & IterationsSet), "property iterations should not be set yet");
                    m_result->setIterations(value);
                    return castState<IterationsSet>();
                }

                AnimationEffectBuilder<STATE | DurationSet>& setDuration(double value)
                {
                    static_assert(!(STATE & DurationSet), "property duration should not be set yet");
                    m_result->setDuration(value);
                    return castState<DurationSet>();
                }

                AnimationEffectBuilder<STATE | DirectionSet>& setDirection(const String& value)
                {
                    static_assert(!(STATE & DirectionSet), "property direction should not be set yet");
                    m_result->setDirection(value);
                    return castState<DirectionSet>();
                }

                AnimationEffectBuilder<STATE | FillSet>& setFill(const String& value)
                {
                    static_assert(!(STATE & FillSet), "property fill should not be set yet");
                    m_result->setFill(value);
                    return castState<FillSet>();
                }

                AnimationEffectBuilder<STATE | BackendNodeIdSet>& setBackendNodeId(int value)
                {
                    static_assert(!(STATE & BackendNodeIdSet), "property backendNodeId should not be set yet");
                    m_result->setBackendNodeId(value);
                    return castState<BackendNodeIdSet>();
                }

                AnimationEffectBuilder<STATE>& setKeyframesRule(std::unique_ptr<protocol::Animation::KeyframesRule> value)
                {
                    m_result->setKeyframesRule(std::move(value));
                    return *this;
                }

                AnimationEffectBuilder<STATE | EasingSet>& setEasing(const String& value)
                {
                    static_assert(!(STATE & EasingSet), "property easing should not be set yet");
                    m_result->setEasing(value);
                    return castState<EasingSet>();
                }

                std::unique_ptr<AnimationEffect> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class AnimationEffect;
                AnimationEffectBuilder()
                    : m_result(new AnimationEffect())
                {
                }

                template <int STEP>
                AnimationEffectBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<AnimationEffectBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Animation::AnimationEffect> m_result;
            };

            static AnimationEffectBuilder<0> create()
            {
                return AnimationEffectBuilder<0>();
            }

        private:
            AnimationEffect()
            {
                m_delay = 0;
                m_endDelay = 0;
                m_iterationStart = 0;
                m_iterations = 0;
                m_duration = 0;
                m_backendNodeId = 0;
            }

            double m_delay;
            double m_endDelay;
            double m_iterationStart;
            double m_iterations;
            double m_duration;
            String m_direction;
            String m_fill;
            int m_backendNodeId;
            Maybe<protocol::Animation::KeyframesRule> m_keyframesRule;
            String m_easing;
        };

        // Keyframes Rule
        class CORE_EXPORT KeyframesRule : public Serializable {
            PROTOCOL_DISALLOW_COPY(KeyframesRule);

        public:
            static std::unique_ptr<KeyframesRule> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~KeyframesRule() override { }

            bool hasName() { return m_name.isJust(); }
            String getName(const String& defaultValue) { return m_name.isJust() ? m_name.fromJust() : defaultValue; }
            void setName(const String& value) { m_name = value; }

            protocol::Array<protocol::Animation::KeyframeStyle>* getKeyframes() { return m_keyframes.get(); }
            void setKeyframes(std::unique_ptr<protocol::Array<protocol::Animation::KeyframeStyle>> value) { m_keyframes = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<KeyframesRule> clone() const;

            template <int STATE>
            class KeyframesRuleBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    KeyframesSet = 1 << 1,
                    AllFieldsSet = (KeyframesSet | 0)
                };

                KeyframesRuleBuilder<STATE>& setName(const String& value)
                {
                    m_result->setName(value);
                    return *this;
                }

                KeyframesRuleBuilder<STATE | KeyframesSet>& setKeyframes(std::unique_ptr<protocol::Array<protocol::Animation::KeyframeStyle>> value)
                {
                    static_assert(!(STATE & KeyframesSet), "property keyframes should not be set yet");
                    m_result->setKeyframes(std::move(value));
                    return castState<KeyframesSet>();
                }

                std::unique_ptr<KeyframesRule> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class KeyframesRule;
                KeyframesRuleBuilder()
                    : m_result(new KeyframesRule())
                {
                }

                template <int STEP>
                KeyframesRuleBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<KeyframesRuleBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Animation::KeyframesRule> m_result;
            };

            static KeyframesRuleBuilder<0> create()
            {
                return KeyframesRuleBuilder<0>();
            }

        private:
            KeyframesRule()
            {
            }

            Maybe<String> m_name;
            std::unique_ptr<protocol::Array<protocol::Animation::KeyframeStyle>> m_keyframes;
        };

        // Keyframe Style
        class CORE_EXPORT KeyframeStyle : public Serializable {
            PROTOCOL_DISALLOW_COPY(KeyframeStyle);

        public:
            static std::unique_ptr<KeyframeStyle> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~KeyframeStyle() override { }

            String getOffset() { return m_offset; }
            void setOffset(const String& value) { m_offset = value; }

            String getEasing() { return m_easing; }
            void setEasing(const String& value) { m_easing = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<KeyframeStyle> clone() const;

            template <int STATE>
            class KeyframeStyleBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    OffsetSet = 1 << 1,
                    EasingSet = 1 << 2,
                    AllFieldsSet = (OffsetSet | EasingSet | 0)
                };

                KeyframeStyleBuilder<STATE | OffsetSet>& setOffset(const String& value)
                {
                    static_assert(!(STATE & OffsetSet), "property offset should not be set yet");
                    m_result->setOffset(value);
                    return castState<OffsetSet>();
                }

                KeyframeStyleBuilder<STATE | EasingSet>& setEasing(const String& value)
                {
                    static_assert(!(STATE & EasingSet), "property easing should not be set yet");
                    m_result->setEasing(value);
                    return castState<EasingSet>();
                }

                std::unique_ptr<KeyframeStyle> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class KeyframeStyle;
                KeyframeStyleBuilder()
                    : m_result(new KeyframeStyle())
                {
                }

                template <int STEP>
                KeyframeStyleBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<KeyframeStyleBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Animation::KeyframeStyle> m_result;
            };

            static KeyframeStyleBuilder<0> create()
            {
                return KeyframeStyleBuilder<0>();
            }

        private:
            KeyframeStyle()
            {
            }

            String m_offset;
            String m_easing;
        };

        // Wrapper for notification params
        class CORE_EXPORT AnimationCreatedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(AnimationCreatedNotification);

        public:
            static std::unique_ptr<AnimationCreatedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~AnimationCreatedNotification() override { }

            String getId() { return m_id; }
            void setId(const String& value) { m_id = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<AnimationCreatedNotification> clone() const;

            template <int STATE>
            class AnimationCreatedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    IdSet = 1 << 1,
                    AllFieldsSet = (IdSet | 0)
                };

                AnimationCreatedNotificationBuilder<STATE | IdSet>& setId(const String& value)
                {
                    static_assert(!(STATE & IdSet), "property id should not be set yet");
                    m_result->setId(value);
                    return castState<IdSet>();
                }

                std::unique_ptr<AnimationCreatedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class AnimationCreatedNotification;
                AnimationCreatedNotificationBuilder()
                    : m_result(new AnimationCreatedNotification())
                {
                }

                template <int STEP>
                AnimationCreatedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<AnimationCreatedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Animation::AnimationCreatedNotification> m_result;
            };

            static AnimationCreatedNotificationBuilder<0> create()
            {
                return AnimationCreatedNotificationBuilder<0>();
            }

        private:
            AnimationCreatedNotification()
            {
            }

            String m_id;
        };

        // Wrapper for notification params
        class CORE_EXPORT AnimationStartedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(AnimationStartedNotification);

        public:
            static std::unique_ptr<AnimationStartedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~AnimationStartedNotification() override { }

            protocol::Animation::Animation* getAnimation() { return m_animation.get(); }
            void setAnimation(std::unique_ptr<protocol::Animation::Animation> value) { m_animation = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<AnimationStartedNotification> clone() const;

            template <int STATE>
            class AnimationStartedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    AnimationSet = 1 << 1,
                    AllFieldsSet = (AnimationSet | 0)
                };

                AnimationStartedNotificationBuilder<STATE | AnimationSet>& setAnimation(std::unique_ptr<protocol::Animation::Animation> value)
                {
                    static_assert(!(STATE & AnimationSet), "property animation should not be set yet");
                    m_result->setAnimation(std::move(value));
                    return castState<AnimationSet>();
                }

                std::unique_ptr<AnimationStartedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class AnimationStartedNotification;
                AnimationStartedNotificationBuilder()
                    : m_result(new AnimationStartedNotification())
                {
                }

                template <int STEP>
                AnimationStartedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<AnimationStartedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Animation::AnimationStartedNotification> m_result;
            };

            static AnimationStartedNotificationBuilder<0> create()
            {
                return AnimationStartedNotificationBuilder<0>();
            }

        private:
            AnimationStartedNotification()
            {
            }

            std::unique_ptr<protocol::Animation::Animation> m_animation;
        };

        // Wrapper for notification params
        class CORE_EXPORT AnimationCanceledNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(AnimationCanceledNotification);

        public:
            static std::unique_ptr<AnimationCanceledNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~AnimationCanceledNotification() override { }

            String getId() { return m_id; }
            void setId(const String& value) { m_id = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<AnimationCanceledNotification> clone() const;

            template <int STATE>
            class AnimationCanceledNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    IdSet = 1 << 1,
                    AllFieldsSet = (IdSet | 0)
                };

                AnimationCanceledNotificationBuilder<STATE | IdSet>& setId(const String& value)
                {
                    static_assert(!(STATE & IdSet), "property id should not be set yet");
                    m_result->setId(value);
                    return castState<IdSet>();
                }

                std::unique_ptr<AnimationCanceledNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class AnimationCanceledNotification;
                AnimationCanceledNotificationBuilder()
                    : m_result(new AnimationCanceledNotification())
                {
                }

                template <int STEP>
                AnimationCanceledNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<AnimationCanceledNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Animation::AnimationCanceledNotification> m_result;
            };

            static AnimationCanceledNotificationBuilder<0> create()
            {
                return AnimationCanceledNotificationBuilder<0>();
            }

        private:
            AnimationCanceledNotification()
            {
            }

            String m_id;
        };

        // ------------- Backend interface.

        class CORE_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse enable() = 0;
            virtual DispatchResponse disable() = 0;
            virtual DispatchResponse getPlaybackRate(double* out_playbackRate) = 0;
            virtual DispatchResponse setPlaybackRate(double in_playbackRate) = 0;
            virtual DispatchResponse getCurrentTime(const String& in_id, double* out_currentTime) = 0;
            virtual DispatchResponse setPaused(std::unique_ptr<protocol::Array<String>> in_animations, bool in_paused) = 0;
            virtual DispatchResponse setTiming(const String& in_animationId, double in_duration, double in_delay) = 0;
            virtual DispatchResponse seekAnimations(std::unique_ptr<protocol::Array<String>> in_animations, double in_currentTime) = 0;
            virtual DispatchResponse releaseAnimations(std::unique_ptr<protocol::Array<String>> in_animations) = 0;
            virtual DispatchResponse resolveAnimation(const String& in_animationId, std::unique_ptr<v8_inspector::protocol::Runtime::API::RemoteObject>* out_remoteObject) = 0;
        };

        // ------------- Frontend interface.

        class CORE_EXPORT Frontend {
        public:
            explicit Frontend(FrontendChannel* frontendChannel)
                : m_frontendChannel(frontendChannel)
            {
            }
            void animationCreated(const String& id);
            void animationStarted(std::unique_ptr<protocol::Animation::Animation> animation);
            void animationCanceled(const String& id);

            void flush();
            void sendRawNotification(const String&);

        private:
            FrontendChannel* m_frontendChannel;
        };

        // ------------- Dispatcher.

        class CORE_EXPORT Dispatcher {
        public:
            static void wire(UberDispatcher*, Backend*);

        private:
            Dispatcher() { }
        };

        // ------------- Metainfo.

        class CORE_EXPORT Metainfo {
        public:
            using BackendClass = Backend;
            using FrontendClass = Frontend;
            using DispatcherClass = Dispatcher;
            static const char domainName[];
            static const char commandPrefix[];
            static const char version[];
        };

    } // namespace Animation
} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_Animation_h)
