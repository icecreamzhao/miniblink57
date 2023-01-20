# Copyright 2015 Google Inc.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
# GYP file to build flag parser
#
{
  'targets': [
    {
      'target_name': 'flags',
      'type': 'static_library',
<<<<<<< HEAD
      'include_dirs': [
          '../include/private',
          '../src/core',
      ],
=======
      'include_dirs': [ '../src/core', ],
>>>>>>> miniblink49
      'sources': [
        '../tools/flags/SkCommandLineFlags.cpp',
        '../tools/flags/SkCommandLineFlags.h',
      ],
      'dependencies': [
        'skia_lib.gyp:skia_lib',
      ],
      'direct_dependent_settings': {
        'include_dirs': [
          '../tools/flags',
        ],
<<<<<<< HEAD
      },
      'conditions': [
        ['skia_gpu', {
          'dependencies': [
            'gputest.gyp:skgputest',
          ],
        }],
      ],
=======
      }
>>>>>>> miniblink49
    },
    {
      'target_name': 'flags_common',
      'type': 'static_library',
<<<<<<< HEAD
      'include_dirs': [
          '../include/gpu',
          '../include/private',
          '../src/gpu',
      ],
      'sources': [
        '../tools/flags/SkCommonFlags.cpp',
        '../tools/flags/SkCommonFlags.h',
        '../tools/flags/SkCommonFlagsConfig.cpp',
        '../tools/flags/SkCommonFlagsConfig.h',
=======
      'sources': [
        '../tools/flags/SkCommonFlags.cpp',
        '../tools/flags/SkCommonFlags.h',
>>>>>>> miniblink49
      ],
      'dependencies': [
        'skia_lib.gyp:skia_lib',
        'flags.gyp:flags',
      ],
      'direct_dependent_settings': {
        'include_dirs': [
<<<<<<< HEAD
          '../include/gpu',
          '../include/private',
          '../src/gpu',
=======
>>>>>>> miniblink49
          '../tools/flags',
        ],
      }
    },
  ],
}
