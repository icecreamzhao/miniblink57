// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebScriptExecutionCallback_h
#define WebScriptExecutionCallback_h

namespace v8 {
class Value;
<<<<<<< HEAD
template <class T>
class Local;
=======
template <class T> class Local;
>>>>>>> miniblink49
}

namespace blink {

<<<<<<< HEAD
template <typename T>
class WebVector;
=======
template <typename T> class WebVector;
>>>>>>> miniblink49

class WebScriptExecutionCallback {
public:
    virtual ~WebScriptExecutionCallback() { }

    // Method to be invoked when the asynchronous script execution is complete.
    // After function call all objects in vector will be collected
<<<<<<< HEAD
    virtual void completed(const WebVector<v8::Local<v8::Value>>&) { }
=======
    virtual void completed(const WebVector<v8::Local<v8::Value> >&) { }
>>>>>>> miniblink49
};

} // namespace blink

#endif // WebScriptExecutionCallback_h
