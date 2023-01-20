# Copyright 2015 Google Inc.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
# Copyright 2015 Google Inc.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

# GYP file for codec project.
{
  'targets': [
    {
      'target_name': 'codec',
      'product_name': 'skia_codec',
      'type': 'static_library',
      'standalone_static_library': 1,
      'dependencies': [
        'core.gyp:*',
        'giflib.gyp:giflib',
<<<<<<< HEAD
        'libjpeg-turbo-selector.gyp:libjpeg-turbo-selector',
        'libpng.gyp:libpng',
        'libwebp.gyp:libwebp',
      ],
      'cflags':[   
        # FIXME: This gets around a warning: "Argument might be clobbered by longjmp". 
        '-Wno-clobbered',
        '-Wno-unknown-warning-option',
      ],
      'include_dirs': [
        '../include/codec',
        '../include/private',
        '../src/codec',
        '../src/core',
        '../src/utils',
      ],
      'sources': [
        '../src/codec/SkAndroidCodec.cpp',
        '../src/codec/SkBmpCodec.cpp',
        '../src/codec/SkBmpMaskCodec.cpp',
        '../src/codec/SkBmpRLECodec.cpp',
        '../src/codec/SkBmpStandardCodec.cpp',
        '../src/codec/SkCodec.cpp',
        '../src/codec/SkGifCodec.cpp',
        '../src/codec/SkIcoCodec.cpp',
        '../src/codec/SkJpegCodec.cpp',
        '../src/codec/SkJpegDecoderMgr.cpp',
        '../src/codec/SkJpegUtility.cpp',
        '../src/codec/SkMaskSwizzler.cpp',
        '../src/codec/SkMasks.cpp',
        '../src/codec/SkPngCodec.cpp',
        '../src/codec/SkSampler.cpp',
        '../src/codec/SkSampledCodec.cpp',
        '../src/codec/SkSwizzler.cpp',
        '../src/codec/SkWbmpCodec.cpp',
        '../src/codec/SkWebpAdapterCodec.cpp',
        '../src/codec/SkWebpCodec.cpp',

        '../src/codec/SkCodecImageGenerator.cpp',
        '../src/ports/SkImageGenerator_skia.cpp',
      ],
      'direct_dependent_settings': {
        'include_dirs': [
          '../include/codec',
        ],
      },
      'defines': [
        # Turn on libjpeg-turbo optimizations since we know that the
        # appropriate version of libjpeg-turbo is present.
        'TURBO_HAS_CROP',
        'TURBO_HAS_SKIP',
        'TURBO_HAS_565',
      ],
      'conditions': [
        ['skia_codec_decodes_raw', {
          'dependencies': [
            'raw_codec',
          ],
        },],
      ],
    }, {
      # RAW codec needs exceptions. Due to that, it is a separate target. Its usage can be
      # controlled by skia_codec_decodes_raw flag.
      'target_name': 'raw_codec',
      'product_name': 'raw_codec',
      'type': 'static_library',
      'dependencies': [
        'core.gyp:*',
        'dng_sdk.gyp:dng_sdk-selector',
        'libjpeg-turbo-selector.gyp:libjpeg-turbo-selector',
        'piex.gyp:piex-selector',
      ],
      'cflags':[
        '-fexceptions',
      ],
      'msvs_settings': {
        'VCCLCompilerTool': {
          # Need this because we are handling exception in SkRawCodec, which will trigger warning
          # C4530. Add this flag as suggested by the compiler.
          'AdditionalOptions': ['/EHsc', ],
        },
      },
      'include_dirs': [
        '../include/codec',
        '../include/private',
=======
        'libjpeg-turbo.gyp:libjpeg-turbo',
        'libwebp.gyp:libwebp',
      ],
      'export_dependent_settings': [
        'libjpeg-turbo.gyp:libjpeg-turbo',
      ],
      'cflags':[
        # FIXME: This gets around a longjmp warning. See
        # http://build.chromium.org/p/client.skia.compile/builders/Build-Ubuntu-GCC-x86_64-Release-Trybot/builds/113/steps/build%20most/logs/stdio
        '-Wno-clobbered',
      ],
      'include_dirs': [
        '../include/codec',
>>>>>>> miniblink49
        '../src/codec',
        '../src/core',
      ],
      'sources': [
<<<<<<< HEAD
        '../src/codec/SkRawAdapterCodec.cpp',
        '../src/codec/SkRawCodec.cpp',
=======
        '../src/codec/SkCodec.cpp',
        '../src/codec/SkCodec_libbmp.cpp',
        '../src/codec/SkCodec_libgif.cpp',
        '../src/codec/SkCodec_libico.cpp',
        '../src/codec/SkCodec_libpng.cpp',
        '../src/codec/SkCodec_wbmp.cpp',
        '../src/codec/SkGifInterlaceIter.cpp',
        '../src/codec/SkJpegCodec.cpp',
        '../src/codec/SkJpegDecoderMgr.cpp',
        '../src/codec/SkJpegUtility_codec.cpp',
        '../src/codec/SkMaskSwizzler.cpp',
        '../src/codec/SkMasks.cpp',
        '../src/codec/SkSwizzler.cpp',
        '../src/codec/SkWebpCodec.cpp',
>>>>>>> miniblink49
      ],
      'direct_dependent_settings': {
        'include_dirs': [
          '../include/codec',
        ],
      },
      'conditions': [
<<<<<<< HEAD
        ['skia_arch_type == "x86" or skia_arch_type == "arm"', {
          'defines': [
            'qDNGBigEndian=0',
          ],
        }],
        ['skia_os == "ios" or skia_os == "mac"', {
          'xcode_settings': {
            'OTHER_CFLAGS': ['-fexceptions'],
            'OTHER_CPLUSPLUSFLAGS': ['-fexceptions'],
          },
        }],
      ],
=======
        [ 'skia_android_framework == 1',
          {
            # TODO(djsollen): this is a temporary dependency until we can update
            # the android framework to a more recent version of libpng.
            'dependencies': [
              'libpng.gyp:libpng',
            ],
            # TODO(msarett): update libjpeg-turbo on Android so we can compile SkJpegCodec
            # for the framework.
            'sources!': [
              '../src/codec/SkJpegCodec.cpp',
              '../src/codec/SkJpegDecoderMgr.cpp',
              '../src/codec/SkJpegUtility_codec.cpp',
            ],
            'dependencies!': [
              'libjpeg-turbo.gyp:libjpeg-turbo',
            ],
          }, {  # !skia_android_framework
            'dependencies': [
              'libpng.gyp:libpng_static',
            ],
            'cflags': [
              '-DTURBO_HAS_SKIP',
            ],
          }
        ]
      ]
>>>>>>> miniblink49
    },
  ],
}
