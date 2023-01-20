# Copyright 2015 Google Inc.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
# This file builds the PDF backend.
{
  'targets': [
    {
<<<<<<< HEAD
      'target_name': 'nopdf',
      'type': 'static_library',
      'dependencies': [ 'skia_lib.gyp:skia_lib', ],
      'sources': [ '<(skia_src_path)/pdf/SkDocument_PDF_None.cpp', ],
      'defines': [ 'SK_SUPPORT_PDF=0', ],
    },
    {
=======
>>>>>>> miniblink49
      'target_name': 'pdf',
      'product_name': 'skia_pdf',
      'type': 'static_library',
      'standalone_static_library': 1,
<<<<<<< HEAD
      'variables': {
        'skia_pdf_use_sfntly%': 1,
        'skia_pdf_less_compression%': 0,  # enable for debugging only
      },
      'dependencies': [
        'skia_lib.gyp:skia_lib',
        'zlib.gyp:zlib',
=======
      'variables': { 'skia_pdf_use_sfntly%': 1, },
      'dependencies': [
        'skia_lib.gyp:skia_lib',
        'skflate.gyp:skflate',
>>>>>>> miniblink49
      ],
      'includes': [
        'pdf.gypi',
      ],
      'include_dirs': [
<<<<<<< HEAD
        '../include/private',
        '../src/core', # needed to get SkGlyphCache.h and SkTextFormatParams.h
        '../src/image',
=======
        '../src/core', # needed to get SkGlyphCache.h and SkTextFormatParams.h
        '../src/pdf',
>>>>>>> miniblink49
        '../src/utils', # needed to get SkBitSet.h
      ],
      'sources': [
        'pdf.gypi', # Makes the gypi appear in IDEs (but does not modify the build).
      ],
      'conditions': [
        [ 'skia_pdf_use_sfntly and not skia_android_framework and \
<<<<<<< HEAD
           skia_os in ["win", "android", "linux", "mac"]',
          { 'dependencies': [ 'sfntly.gyp:sfntly' ] }
        ],
        [ 'skia_pdf_less_compression',
          {'defines': ['SK_PDF_LESS_COMPRESSION'] }
        ],
=======
           skia_os in ["win", "android", "linux", "chromeos", "mac"]',
          { 'dependencies': [ 'sfntly.gyp:sfntly' ] }
        ],
>>>>>>> miniblink49
        [ 'skia_android_framework', {
            # Add SFTNLY support for PDF (which in turns depends on ICU)
            'include_dirs': [
              'external/sfntly/cpp/src',
            ],
            'libraries': [
              'libsfntly.a',
              '-licuuc',
              '-licui18n',
            ],
          }
        ],
      ],
<<<<<<< HEAD
      'direct_dependent_settings': {
        'defines': [ 'SK_SUPPORT_PDF=1', ],
=======
      # This section makes all targets that depend on this target
      # #define SK_SUPPORT_PDF and have access to the pdf header files.
      'direct_dependent_settings': {
        'defines': [
          'SK_SUPPORT_PDF',
        ],
>>>>>>> miniblink49
        'include_dirs': [
          '../include/core',  # SkDocument.h
        ],
      },
    },
  ],
}
