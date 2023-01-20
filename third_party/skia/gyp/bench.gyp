# Copyright 2015 Google Inc.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
# GYP file to build performance testbench.
#
{
  'includes': [
    'apptype_console.gypi',
  ],
  'targets': [
    {
      'target_name': 'nanobench',
      'type': 'executable',
      'sources': [
        '../gm/gm.cpp',
      ],
      'includes': [
        'bench.gypi',
        'gmslides.gypi',
      ],
<<<<<<< HEAD
      'include_dirs' : [
        '../src/image',
      ],
=======
>>>>>>> miniblink49
      'dependencies': [
        'flags.gyp:flags_common',
        'jsoncpp.gyp:jsoncpp',
        'skia_lib.gyp:skia_lib',
        'tools.gyp:crash_handler',
        'tools.gyp:proc_stats',
<<<<<<< HEAD
        'tools.gyp:thermal_manager',
=======
>>>>>>> miniblink49
        'tools.gyp:timer',
      ],
      'conditions': [
        ['skia_android_framework', {
          'libraries': [
<<<<<<< HEAD
            'skia_static.a',
            '-lhwui',
          ],
          'include_dirs': [
            '../../../frameworks/base/libs/hwui/',
          ],
          'dependencies': [
            'tools.gyp:android_utils',
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
          ],
          'dependencies': [
            'utils.gyp:android_utils',
>>>>>>> miniblink49
          ],
        }],
      ],
    },
  ],
}
