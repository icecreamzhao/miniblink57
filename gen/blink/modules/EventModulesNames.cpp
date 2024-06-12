// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "EventModulesNames.h"

#include "wtf/StdLibExtras.h"

// Generated from:
// - gen/blink/EventModulesInterfaces.in

namespace blink {
namespace EventNames {

    using namespace WTF;

    void* ModulesNamesStorage[EventModulesNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

    const AtomicString& BeforeInstallPromptEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[0];
    const AtomicString& SyncEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[1];
    const AtomicString& DeviceLightEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[2];
    const AtomicString& DeviceMotionEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[3];
    const AtomicString& DeviceOrientationEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[4];
    const AtomicString& MediaEncryptedEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[5];
    const AtomicString& MediaKeyMessageEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[6];
    const AtomicString& GamepadEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[7];
    const AtomicString& IDBVersionChangeEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[8];
    const AtomicString& BlobEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[9];
    const AtomicString& MediaStreamEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[10];
    const AtomicString& MediaStreamTrackEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[11];
    const AtomicString& NotificationEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[12];
    const AtomicString& PaymentRequestEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[13];
    const AtomicString& PaymentRequestUpdateEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[14];
    const AtomicString& RTCDTMFToneChangeEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[15];
    const AtomicString& RTCDataChannelEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[16];
    const AtomicString& RTCPeerConnectionIceEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[17];
    const AtomicString& PresentationConnectionAvailableEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[18];
    const AtomicString& PresentationConnectionCloseEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[19];
    const AtomicString& PushEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[20];
    const AtomicString& SensorErrorEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[21];
    const AtomicString& ExtendableEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[22];
    const AtomicString& ExtendableMessageEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[23];
    const AtomicString& FetchEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[24];
    const AtomicString& ForeignFetchEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[25];
    const AtomicString& InstallEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[26];
    const AtomicString& SpeechRecognitionError = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[27];
    const AtomicString& SpeechRecognitionEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[28];
    const AtomicString& SpeechSynthesisEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[29];
    const AtomicString& StorageEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[30];
    const AtomicString& VRDisplayEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[31];
    const AtomicString& AudioProcessingEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[32];
    const AtomicString& OfflineAudioCompletionEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[33];
    const AtomicString& WebGLContextEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[34];
    const AtomicString& MIDIConnectionEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[35];
    const AtomicString& MIDIMessageEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[36];
    const AtomicString& CloseEvent = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[37];

    void initModules()
    {
        struct NameEntry {
            const char* name;
            unsigned hash;
            unsigned char length;
        };

        static const NameEntry kNames[] = {
            { "BeforeInstallPromptEvent", 4066404, 24 },
            { "SyncEvent", 5657331, 9 },
            { "DeviceLightEvent", 8667494, 16 },
            { "DeviceMotionEvent", 12345260, 17 },
            { "DeviceOrientationEvent", 858735, 22 },
            { "MediaEncryptedEvent", 13703864, 19 },
            { "MediaKeyMessageEvent", 4827241, 20 },
            { "GamepadEvent", 11020890, 12 },
            { "IDBVersionChangeEvent", 7770749, 21 },
            { "BlobEvent", 11517662, 9 },
            { "MediaStreamEvent", 328267, 16 },
            { "MediaStreamTrackEvent", 13109664, 21 },
            { "NotificationEvent", 8638709, 17 },
            { "PaymentRequestEvent", 303922, 19 },
            { "PaymentRequestUpdateEvent", 6504900, 25 },
            { "RTCDTMFToneChangeEvent", 16457152, 22 },
            { "RTCDataChannelEvent", 1105547, 19 },
            { "RTCPeerConnectionIceEvent", 11405375, 25 },
            { "PresentationConnectionAvailableEvent", 12337962, 36 },
            { "PresentationConnectionCloseEvent", 7051740, 32 },
            { "PushEvent", 508183, 9 },
            { "SensorErrorEvent", 7058930, 16 },
            { "ExtendableEvent", 2731257, 15 },
            { "ExtendableMessageEvent", 4738899, 22 },
            { "FetchEvent", 6447122, 10 },
            { "ForeignFetchEvent", 58197, 17 },
            { "InstallEvent", 13461741, 12 },
            { "SpeechRecognitionError", 13037355, 22 },
            { "SpeechRecognitionEvent", 6869292, 22 },
            { "SpeechSynthesisEvent", 17758, 20 },
            { "StorageEvent", 5246637, 12 },
            { "VRDisplayEvent", 1333207, 14 },
            { "AudioProcessingEvent", 9607128, 20 },
            { "OfflineAudioCompletionEvent", 6072331, 27 },
            { "WebGLContextEvent", 8713913, 17 },
            { "MIDIConnectionEvent", 5515626, 19 },
            { "MIDIMessageEvent", 12787442, 16 },
            { "CloseEvent", 11722244, 10 },
        };

        for (size_t i = 0; i < WTF_ARRAY_LENGTH(kNames); i++) {
            StringImpl* stringImpl = StringImpl::createStatic(kNames[i].name, kNames[i].length, kNames[i].hash);
            void* address = reinterpret_cast<AtomicString*>(&ModulesNamesStorage) + i;
            new (address) AtomicString(stringImpl);
        }
    }

} // EventNames
} // namespace blink
