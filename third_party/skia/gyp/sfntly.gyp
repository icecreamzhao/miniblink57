# Copyright (c) 2011 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
{
  'targets': [
    {
      'target_name': 'sfntly',
      'type': 'static_library',
      'includes': [
        'common_conditions.gypi',
        'common_variables.gypi',
      ],
      'variables': {
<<<<<<< HEAD
        'sfntly_src_path': '../third_party/externals/sfntly/cpp/src',
=======
        'sfntly_src_path': '../third_party/externals/sfntly',
>>>>>>> miniblink49
      },
      'direct_dependent_settings': {
        'include_dirs': [ '<(sfntly_src_path)/sample/chromium', ],
        'defines': [
          'SK_SFNTLY_SUBSETTER="font_subsetter.h"',
        ],
      },
      'sources': [
        '<(sfntly_src_path)/sample/chromium/font_subsetter.cc',
        '<(sfntly_src_path)/sample/chromium/subsetter_impl.cc',
<<<<<<< HEAD
        '<!@(python find.py "<(sfntly_src_path)/sfntly" "*.c*")'
=======
        '<!@(python find.py ../third_party/externals/sfntly/sfntly "*.c*")'
>>>>>>> miniblink49
      ],
      'include_dirs': [
        '<(sfntly_src_path)',
      ],
      'defines': [
        'SFNTLY_NO_EXCEPTION',
      ],
      'dependencies' : [
        'icu.gyp:icuuc',
      ],
      'conditions': [
        [ 'skia_os == "win"',
          {
<<<<<<< HEAD
            'defines': [ 'WIN32', 'NOMINMAX', ],
=======
            'defines': [ 'WIN32', ],
>>>>>>> miniblink49
            'msvs_settings': {
              'VCCLCompilerTool': {
                'AdditionalOptions': [ '/EHsc' ],
              },
            },
          }
        ],
<<<<<<< HEAD
        [ 'skia_os in ["linux", "freebsd", "openbsd", "solaris"]',
=======
        [ 'skia_os in ["linux", "freebsd", "openbsd", "solaris", "chromeos"]',
>>>>>>> miniblink49
          { 'link_settings': { 'libraries': [ '-lpthread', ], }, },
        ],
      ],
      # TODO(jschuh): http://crbug.com/167187
      'msvs_disabled_warnings': [ 4267, 4244 ],
    },
  ]
}
