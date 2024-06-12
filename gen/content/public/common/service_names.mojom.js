// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("content/public/common/service_names.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var kBrowserServiceName = "content_browser";
  var kGpuServiceName = "content_gpu";
  var kPluginServiceName = "content_plugin";
  var kRendererServiceName = "content_renderer";
  var kUtilityServiceName = "content_utility";


  var exports = {};
  exports.kBrowserServiceName = kBrowserServiceName;
  exports.kGpuServiceName = kGpuServiceName;
  exports.kPluginServiceName = kPluginServiceName;
  exports.kRendererServiceName = kRendererServiceName;
  exports.kUtilityServiceName = kUtilityServiceName;

  return exports;
});