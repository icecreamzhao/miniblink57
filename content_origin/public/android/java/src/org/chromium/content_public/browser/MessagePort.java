// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.content_public.browser;

import android.os.Handler;

import org.chromium.base.annotations.UsedByReflection;

/**
 * Interface for message ports that handle postMessage requests.
 */
@UsedByReflection("")
public interface MessagePort {
    /**
     * The message callback for receiving messages.
     */
    public interface MessageCallback {
        /**
         * Sent when the associated {@link MessagePort} gets a postMessage.
         * @param message   The message that was received.
         * @param sentPorts The {@link MessagePort}s that were sent if any.
         */
        void onMessage(String message, MessagePort[] sentPorts);
    }

    /**
     * @return Whether the message port is ready for receiving
     *         {@link MessagePort#postMessage(String, MessagePort[])} calls.
     */
    boolean isReady();

    /**
     * Close the port for use.
     */
    void close();

    /**
     * @return Whether the port has been closed before.
     */
    boolean isClosed();

    /**
     * @return Whether the port has been transferred using
     *         {@link MessagePort#postMessage(String, MessagePort[])} before.
     */
    boolean isTransferred();

    /**
     * @return Whether the port has been started.
     */
    boolean isStarted();

    /**
     * Sets the handler and message callback to be used for the messages received. If the given
     * {@link Handler} is not null, then the callback is received on the handler thread, if not
     * it is on UI thread.
     *
     * See {@link MessagePort.MessageCallback}
     */
    void setMessageCallback(MessageCallback messageCallback, Handler handler);

    /**
     * Send a postMessage request through this port to its designated receiving end.
     * @param message   The message to be sent.
     * @param sentPorts The ports to be transferred.
     */
    void postMessage(String message, MessagePort[] sentPorts);
}
