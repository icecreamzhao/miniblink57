// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebSourceBufferClient_h
#define WebSourceBufferClient_h

<<<<<<< HEAD
#include "WebMediaPlayer.h"
#include "WebString.h"
#include "WebVector.h"

namespace blink {

// Interface that the media engine uses to signal Blink's Media Source
// extensions module.
=======
namespace blink {

>>>>>>> miniblink49
class WebSourceBufferClient {
public:
    virtual ~WebSourceBufferClient() { }

<<<<<<< HEAD
    // Complete media track info: track type, unique track id, kind, label,
    // language.
    struct MediaTrackInfo {
        WebMediaPlayer::TrackType trackType;
        WebMediaPlayer::TrackId id;
        WebString byteStreamTrackID;
        WebString kind;
        WebString label;
        WebString language;
    };

    // Notifies SourceBuffer that parsing of a new init segment has been completed
    // successfully. The input parameter is a collection of information about
    // media tracks found in the new init segment. The return value is true in
    // case of success.
    virtual bool initializationSegmentReceived(
        const WebVector<MediaTrackInfo>& tracks)
        = 0;
=======
    // FIXME: Add a track collection parameter here.
    virtual void initializationSegmentReceived() = 0;
>>>>>>> miniblink49
};

} // namespace blink

#endif // WebSourceBufferClient_h
