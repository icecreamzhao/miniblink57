# Copyright 2014 Google Inc.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

{
<<<<<<< HEAD
  'variables': {
    'skia_warnings_as_errors': 0,
  },
  'targets': [
  {
      'target_name': 'zlib',
      'conditions': [
        [ 'skia_android_framework', {
          'type': 'none',
          'direct_dependent_settings': {
              'include_dirs': [ 'external/zlib' ],
              'link_settings': { 'libraries': [ '-lz' ] },
          },
        }, {
          'type': 'static_library',
          'variables': {
            'skia_zlib_flags' : [
              '-Wno-unused-value',
              '-Wno-shift-negative-value',
              '-Wno-unknown-warning-option',
            ],
          },
          'cflags': [ '<@(skia_zlib_flags)' ],
          'xcode_settings': { 'WARNING_CFLAGS': [ '<@(skia_zlib_flags)' ], },
=======
  'targets': [
  {
    # Only used by win, down below.
    'target_name' : 'zlib_x86_simd',
    'type': 'static_library',
    'cflags' : ['-msse4.2', '-mpclmul'],
    'sources' : [
      '../third_party/externals/zlib/crc_folding.c',
      '../third_party/externals/zlib/fill_window_sse.c',
    ],
      'conditions': [
        ['skia_clang_build==1', {
          'msvs_settings': {
            'VCCLCompilerTool': {
              'AdditionalOptions': [ '-msse4.2', '-mpclmul' ],
            },
          },
        }],
      ],
  },
  {
      'target_name': 'zlib',
      'direct_dependent_settings': {
        'conditions': [
          [ 'skia_android_framework', { 'include_dirs': [ 'external/zlib' ] }],
          [ 'skia_os == "mac" or skia_os == "ios"', {
              # XCode needs and explicit file path, not a logical name like -lz.
              'link_settings': { 'libraries': [ '$(SDKROOT)/usr/lib/libz.dylib' ] },
          }],
          [ 'skia_os not in ["mac", "ios", "win"]',{
              'link_settings': { 'libraries': [ '-lz' ] },
          }]
        ],
      },
      'conditions': [
        [ 'skia_os != "win"', {
          'type': 'none',
        }, {
          # win
          'type': 'static_library',
>>>>>>> miniblink49
          'sources': [
            '../third_party/externals/zlib/adler32.c',
            '../third_party/externals/zlib/compress.c',
            '../third_party/externals/zlib/crc32.c',
<<<<<<< HEAD
            '../third_party/externals/zlib/deflate.c',
            '../third_party/externals/zlib/gzclose.c',
=======
            '../third_party/externals/zlib/crc32.h',
            '../third_party/externals/zlib/deflate.c',
            '../third_party/externals/zlib/deflate.h',
            '../third_party/externals/zlib/gzclose.c',
            '../third_party/externals/zlib/gzguts.h',
>>>>>>> miniblink49
            '../third_party/externals/zlib/gzlib.c',
            '../third_party/externals/zlib/gzread.c',
            '../third_party/externals/zlib/gzwrite.c',
            '../third_party/externals/zlib/infback.c',
            '../third_party/externals/zlib/inffast.c',
<<<<<<< HEAD
            '../third_party/externals/zlib/inflate.c',
            '../third_party/externals/zlib/inftrees.c',
            '../third_party/externals/zlib/simd_stub.c',
            '../third_party/externals/zlib/trees.c',
            '../third_party/externals/zlib/uncompr.c',
            '../third_party/externals/zlib/zutil.c',
=======
            '../third_party/externals/zlib/inffast.h',
            '../third_party/externals/zlib/inffixed.h',
            '../third_party/externals/zlib/inflate.c',
            '../third_party/externals/zlib/inflate.h',
            '../third_party/externals/zlib/inftrees.c',
            '../third_party/externals/zlib/inftrees.h',
            '../third_party/externals/zlib/mozzconf.h',
            '../third_party/externals/zlib/trees.c',
            '../third_party/externals/zlib/trees.h',
            '../third_party/externals/zlib/uncompr.c',
            '../third_party/externals/zlib/x86.h',
            '../third_party/externals/zlib/x86.c',
            '../third_party/externals/zlib/zconf.h',
            '../third_party/externals/zlib/zlib.h',
            '../third_party/externals/zlib/zutil.c',
            '../third_party/externals/zlib/zutil.h',
>>>>>>> miniblink49
          ],
          'include_dirs': [
            '../third_party/externals/zlib/',
          ],
          'direct_dependent_settings': {
            'include_dirs': [
              '../third_party/externals/zlib',
            ],
          },
<<<<<<< HEAD
=======
          'dependencies': [
            'zlib_x86_simd',
          ],
>>>>>>> miniblink49
          'defines': [
            '_CRT_NONSTDC_NO_DEPRECATE',
          ],
        }],
      ],
  }],
}
