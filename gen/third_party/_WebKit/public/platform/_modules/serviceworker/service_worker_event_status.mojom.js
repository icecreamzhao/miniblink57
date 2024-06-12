// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/platform/modules/serviceworker/service_worker_event_status.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var ServiceWorkerEventStatus = {};
  ServiceWorkerEventStatus.COMPLETED = 0;
  ServiceWorkerEventStatus.REJECTED = ServiceWorkerEventStatus.COMPLETED + 1;
  ServiceWorkerEventStatus.ABORTED = ServiceWorkerEventStatus.REJECTED + 1;
  ServiceWorkerEventStatus.MAX = ServiceWorkerEventStatus.ABORTED;

  ServiceWorkerEventStatus.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  ServiceWorkerEventStatus.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };


  var exports = {};
  exports.ServiceWorkerEventStatus = ServiceWorkerEventStatus;

  return exports;
});