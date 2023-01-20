# Copyright 2015 Google Inc.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
# GYP for "dm" (Diamond Master, a.k.a Dungeon master, a.k.a GM 2).
{
    'includes': [ 'apptype_console.gypi' ],

    'targets': [{
        'target_name': 'dm',
        'type': 'executable',
        'includes': [
          'dm.gypi',
        ],
        'conditions': [
          ['skia_android_framework', {
              'libraries': [
<<<<<<< HEAD
                  'skia_static.a',
                  'hwui_static.a',
=======
                  '-lskia',
                  '-landroid',
                  '-lgui',
                  '-lhwui',
                  '-lutils',
              ],
              'include_dirs': [
                  '../../../frameworks/base/libs/hwui/',
                  '../../../frameworks/native/include/',
>>>>>>> miniblink49
              ],
              'sources': [
                '../dm/DMSrcSinkAndroid.cpp',
              ],
              'dependencies': [
<<<<<<< HEAD
                'tools.gyp:android_utils',
=======
                'utils.gyp:android_utils',
>>>>>>> miniblink49
              ],
          }],
        ],
    }]
}
