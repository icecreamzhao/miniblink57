// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "EventTargetModulesNames.h"

#include "wtf/StdLibExtras.h"

// Generated from:
// - ../../third_party/WebKit/Source/modules/EventTargetModulesFactory.in

namespace blink {
namespace EventTargetNames {

    using namespace WTF;

    void* ModulesNamesStorage[EventTargetModulesNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

    const AtomicString& BatteryManager = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[0];
    const AtomicString& BluetoothDevice = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[1];
    const AtomicString& BluetoothRemoteGATTCharacteristic = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[2];
    const AtomicString& CompositorWorker = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[3];
    const AtomicString& CompositorWorkerGlobalScope = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[4];
    const AtomicString& MediaKeySession = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[5];
    const AtomicString& FileWriter = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[6];
    const AtomicString& ImageCapture = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[7];
    const AtomicString& IDBDatabase = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[8];
    const AtomicString& IDBOpenDBRequest = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[9];
    const AtomicString& IDBRequest = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[10];
    const AtomicString& IDBTransaction = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[11];
    const AtomicString& MediaRecorder = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[12];
    const AtomicString& MediaSource = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[13];
    const AtomicString& SourceBuffer = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[14];
    const AtomicString& SourceBufferList = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[15];
    const AtomicString& MediaDevices = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[16];
    const AtomicString& MediaStream = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[17];
    const AtomicString& MediaStreamTrack = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[18];
    const AtomicString& RTCDTMFSender = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[19];
    const AtomicString& RTCDataChannel = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[20];
    const AtomicString& RTCPeerConnection = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[21];
    const AtomicString& NetworkInformation = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[22];
    const AtomicString& Notification = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[23];
    const AtomicString& PaymentRequest = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[24];
    const AtomicString& PermissionStatus = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[25];
    const AtomicString& PresentationAvailability = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[26];
    const AtomicString& PresentationConnection = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[27];
    const AtomicString& PresentationConnectionList = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[28];
    const AtomicString& PresentationRequest = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[29];
    const AtomicString& RemotePlayback = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[30];
    const AtomicString& ScreenOrientation = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[31];
    const AtomicString& Sensor = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[32];
    const AtomicString& ServiceWorker = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[33];
    const AtomicString& ServiceWorkerContainer = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[34];
    const AtomicString& ServiceWorkerGlobalScope = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[35];
    const AtomicString& ServiceWorkerRegistration = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[36];
    const AtomicString& SpeechRecognition = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[37];
    const AtomicString& SpeechSynthesis = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[38];
    const AtomicString& SpeechSynthesisUtterance = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[39];
    const AtomicString& VRDisplay = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[40];
    const AtomicString& AudioContext = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[41];
    const AtomicString& AudioNode = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[42];
    const AtomicString& MIDIAccess = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[43];
    const AtomicString& MIDIInput = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[44];
    const AtomicString& MIDIPort = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[45];
    const AtomicString& DOMWebSocket = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[46];
    const AtomicString& USB = reinterpret_cast<AtomicString*>(&ModulesNamesStorage)[47];

    void initModules()
    {
        struct NameEntry {
            const char* name;
            unsigned hash;
            unsigned char length;
        };

        static const NameEntry kNames[] = {
            { "BatteryManager", 5049459, 14 },
            { "BluetoothDevice", 14102450, 15 },
            { "BluetoothRemoteGATTCharacteristic", 3805326, 33 },
            { "CompositorWorker", 9970284, 16 },
            { "CompositorWorkerGlobalScope", 7405197, 27 },
            { "MediaKeySession", 1701501, 15 },
            { "FileWriter", 15152482, 10 },
            { "ImageCapture", 3204179, 12 },
            { "IDBDatabase", 1126017, 11 },
            { "IDBOpenDBRequest", 8388818, 16 },
            { "IDBRequest", 16217380, 10 },
            { "IDBTransaction", 13326789, 14 },
            { "MediaRecorder", 9531693, 13 },
            { "MediaSource", 10009800, 11 },
            { "SourceBuffer", 3244577, 12 },
            { "SourceBufferList", 5225283, 16 },
            { "MediaDevices", 7815368, 12 },
            { "MediaStream", 5095066, 11 },
            { "MediaStreamTrack", 16623886, 16 },
            { "RTCDTMFSender", 7965945, 13 },
            { "RTCDataChannel", 16002100, 14 },
            { "RTCPeerConnection", 11238437, 17 },
            { "NetworkInformation", 3171974, 18 },
            { "Notification", 7262241, 12 },
            { "PaymentRequest", 7625983, 14 },
            { "PermissionStatus", 4818911, 16 },
            { "PresentationAvailability", 10735288, 24 },
            { "PresentationConnection", 2995870, 22 },
            { "PresentationConnectionList", 14875970, 26 },
            { "PresentationRequest", 4728545, 19 },
            { "RemotePlayback", 14509464, 14 },
            { "ScreenOrientation", 16006315, 17 },
            { "Sensor", 266785, 6 },
            { "ServiceWorker", 3155984, 13 },
            { "ServiceWorkerContainer", 6814814, 22 },
            { "ServiceWorkerGlobalScope", 16474009, 24 },
            { "ServiceWorkerRegistration", 11774198, 25 },
            { "SpeechRecognition", 1914212, 17 },
            { "SpeechSynthesis", 9951205, 15 },
            { "SpeechSynthesisUtterance", 12730322, 24 },
            { "VRDisplay", 2701451, 9 },
            { "AudioContext", 5207992, 12 },
            { "AudioNode", 5081561, 9 },
            { "MIDIAccess", 13252796, 10 },
            { "MIDIInput", 13226940, 9 },
            { "MIDIPort", 15710269, 8 },
            { "DOMWebSocket", 15572381, 12 },
            { "USB", 6302079, 3 },
        };

        for (size_t i = 0; i < WTF_ARRAY_LENGTH(kNames); i++) {
            StringImpl* stringImpl = StringImpl::createStatic(kNames[i].name, kNames[i].length, kNames[i].hash);
            void* address = reinterpret_cast<AtomicString*>(&ModulesNamesStorage) + i;
            new (address) AtomicString(stringImpl);
        }
    }

} // EventTargetNames
} // namespace blink
