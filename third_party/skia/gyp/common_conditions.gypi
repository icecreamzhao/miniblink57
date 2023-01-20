# Copyright 2015 Google Inc.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

# conditions used in both common.gypi and skia.gyp in chromium
#
{
  'defines': [
    'SK_ALLOW_STATIC_GLOBAL_INITIALIZERS=<(skia_static_initializers)',
    'SK_SUPPORT_GPU=<(skia_gpu)',
<<<<<<< HEAD
    'SK_FORCE_DISTANCE_FIELD_TEXT=<(skia_force_distance_field_text)',
    
    # Indicate that all dependency libraries are present.  Clients that
    # are missing some of the required decoding libraries may choose
    # not to define these.  This will disable some decoder and encoder
    # features.
    'SK_HAS_GIF_LIBRARY',
    'SK_HAS_JPEG_LIBRARY',
    'SK_HAS_PNG_LIBRARY',
    'SK_HAS_WEBP_LIBRARY',

    # Temporarily test against the QCMS library.
    'SK_TEST_QCMS',
  ],
  'conditions' : [
    [ 'skia_is_bot', {
      'defines': [ 'SK_IS_BOT' ],
    }],
    [ 'skia_codec_decodes_raw', {
      'defines': [
        'SK_CODEC_DECODES_RAW',
      ],
    }],
=======
    'SK_SUPPORT_OPENCL=<(skia_opencl)',
    'SK_FORCE_DISTANCE_FIELD_TEXT=<(skia_force_distance_field_text)',
  ],
  'conditions' : [
>>>>>>> miniblink49
    ['skia_pic', {
     'cflags': [
       '-fPIC',
     ],
     'conditions' : [
      # FIXME: The reason we don't do this on Android is due to the way
      # we build the executables/skia_launcher on Android. See
      # https://codereview.chromium.org/406613003/diff/1/gyp/common_conditions.gypi#newcode455
      ['skia_os != "android"', {
       'target_conditions': [
         [ '_type == "executable"', {
           'cflags': [ '-fPIE' ],
           'ldflags': [ '-pie' ],
         }],
       ],
      }],
     ],
    }],

    # As of M35, Chrome requires SSE2 on x86 (and SSSE3 on Mac).
    [ 'skia_arch_type == "x86"', {
      'cflags': [
        '-msse2',
        '-mfpmath=sse',
      ],
    }],

    [ 'skia_os == "win"',
      {
        'defines': [
          'SK_BUILD_FOR_WIN32',
          '_CRT_SECURE_NO_WARNINGS',
          'GR_GL_FUNCTION_TYPE=__stdcall',
<<<<<<< HEAD
          '_HAS_EXCEPTIONS=0',
          'WIN32_LEAN_AND_MEAN',
          'NOMINMAX',
=======
>>>>>>> miniblink49
        ],
        'msvs_disabled_warnings': [
            4275,  # An exported class was derived from a class that was not exported
            4345,  # This is an FYI about a behavior change from long ago. Chrome stifles it too.
            4355,  # 'this' used in base member initializer list. Off by default in newer compilers.
        ],
        'msvs_cygwin_shell': 0,
        'msvs_settings': {
          'VCCLCompilerTool': {
            'WarningLevel': '3',
            'ProgramDataBaseFileName': '$(OutDir)\\$(ProjectName).pdb',
            'DebugInformationFormat': '3',
            'ExceptionHandling': '0',
            'AdditionalOptions': [ '/MP', ],
          },
          'VCLinkerTool': {
            'LargeAddressAware': 2,  # 2 means "Yes, please let me use more RAM on 32-bit builds."
            'AdditionalDependencies': [
              'OpenGL32.lib',
              'usp10.lib',

              # Prior to gyp r1584, the following were included automatically.
              'kernel32.lib',
              'gdi32.lib',
              'winspool.lib',
              'comdlg32.lib',
              'advapi32.lib',
              'shell32.lib',
              'ole32.lib',
              'oleaut32.lib',
              'user32.lib',
              'uuid.lib',
              'odbc32.lib',
              'odbccp32.lib',
              'DelayImp.lib',
            ],
          },
        },
        'configurations': {
          'Debug': {
            'msvs_settings': {
              'VCCLCompilerTool': {
                'DebugInformationFormat': '4', # editAndContiue (/ZI)
                'Optimization': '0',           # optimizeDisabled (/Od)
                'PreprocessorDefinitions': ['_DEBUG'],
                'RuntimeLibrary': '3',         # rtMultiThreadedDebugDLL (/MDd)
                'RuntimeTypeInfo': 'false',      # /GR-
              },
              'VCLinkerTool': {
                'GenerateDebugInformation': 'true', # /DEBUG
                'LinkIncremental': '2',             # /INCREMENTAL
              },
            },
          },
          'Release': {
            'msvs_settings': {
              'VCCLCompilerTool': {
                'DebugInformationFormat': '3',      # programDatabase (/Zi)
                'Optimization': '<(skia_release_optimization_level)',
               # Changing the floating point model requires rebaseling gm images
               #'FloatingPointModel': '2',          # fast (/fp:fast)
                'FavorSizeOrSpeed': '1',            # speed (/Ot)
                'PreprocessorDefinitions': ['NDEBUG'],
                'RuntimeLibrary': '2',              # rtMultiThreadedDLL (/MD)
                'EnableEnhancedInstructionSet': '2',# /arch:SSE2
                'RuntimeTypeInfo': 'false',         # /GR-
              },
              'VCLinkerTool': {
                'GenerateDebugInformation': 'true', # /DEBUG
              },
            },
          },
        },
        'conditions' : [
          # Gyp's ninja generator depends on these specially named
          # configurations to build 64-bit on Windows.
<<<<<<< HEAD
          # See https://bug.skia.org/2348
=======
          # See http://skbug.com/2348
>>>>>>> miniblink49
          #
          # We handle the 64- vs 32-bit variations elsewhere, so I think it's
          # OK for us to just make these inherit non-archwidth-specific
          # configurations without modification.
          #
<<<<<<< HEAD
          # See https://bug.skia.org/2442 : These targets cause problems in the
=======
          # See http://skbug.com/2442 : These targets cause problems in the
>>>>>>> miniblink49
          # MSVS build, so only include them if gyp is generating a ninja build.
          [ '"ninja" in "<!(echo %GYP_GENERATORS%)"', {
            'configurations': {
              'Debug_x64': {
                'inherit_from': ['Debug'],
                'msvs_settings': {
                  'VCCLCompilerTool': {
                     # /ZI is not supported on 64bit
                    'DebugInformationFormat': '3', # programDatabase (/Zi)
                  },
                },
              },
              'Release_x64': {
                'inherit_from': ['Release'],
                'msvs_settings': {
                  'VCCLCompilerTool': {
                     # Don't specify /arch. SSE2 is implied by 64bit and specifying it warns.
                    'EnableEnhancedInstructionSet': '0', #
                  },
                },
              },
              'Release_Developer_x64': {
                'inherit_from': ['Release_Developer'],
                'msvs_settings': {
                  'VCCLCompilerTool': {
                     # Don't specify /arch. SSE2 is implied by 64bit and specifying it warns.
                    'EnableEnhancedInstructionSet': '0', #
                  },
                },
              },
            },
          }],
<<<<<<< HEAD
          [ 'skia_arch_type == "x86_64"', {
            'msvs_configuration_platform': 'x64',
          }],
          [ 'skia_arch_type == "x86"', {
=======
          [ 'skia_arch_width == 64', {
            'msvs_configuration_platform': 'x64',
          }],
          [ 'skia_arch_width == 32', {
>>>>>>> miniblink49
            'msvs_configuration_platform': 'Win32',
          }],
          [ 'skia_warnings_as_errors', {
            'msvs_settings': {
              'VCCLCompilerTool': {
                'WarnAsError': 'true',
                'AdditionalOptions': [
                  '/we4189', # initialized but unused var warning
<<<<<<< HEAD
                  '/we4238', # taking address of rvalue
                  '/we4239', # assigning rvalues to non-const lvalues
=======
>>>>>>> miniblink49
                ],
              },
            },
          }],
          [ 'skia_win_exceptions', {
            'msvs_settings': {
              'VCCLCompilerTool': {
                'AdditionalOptions': [
                  '/EHsc',
                ],
              },
            },
          }],
          [ 'skia_win_ltcg', {
            'configurations': {
              'Release': {
                'msvs_settings': {
                  'VCCLCompilerTool': {
                    'WholeProgramOptimization': 'true', #/GL
                  },
                  'VCLinkerTool': {
                    'LinkTimeCodeGeneration': '1',      # useLinkTimeCodeGeneration /LTCG
                  },
                  'VCLibrarianTool': {
                    'LinkTimeCodeGeneration': 'true',   # useLinkTimeCodeGeneration /LTCG
                  },
                },
              },
            },
          }],
        ],
      },
    ],

    # The following section is common to linux + derivatives and android
<<<<<<< HEAD
    [ 'skia_os in ["linux", "freebsd", "openbsd", "solaris", "android"]',
=======
    [ 'skia_os in ["linux", "freebsd", "openbsd", "solaris", "chromeos", "android"]',
>>>>>>> miniblink49
      {
        'cflags': [
          '-g',
          '-fno-exceptions',
          '-fstrict-aliasing',

          '-Wall',
          '-Wextra',
          '-Winit-self',
          '-Wpointer-arith',
          '-Wsign-compare',
<<<<<<< HEAD
          '-Wvla',
=======
>>>>>>> miniblink49

          '-Wno-unused-parameter',
        ],
        'cflags_cc': [
          '-std=c++11',
          '-fno-rtti',
<<<<<<< HEAD
          '-fno-threadsafe-statics',
          '-Wnon-virtual-dtor',
        ],
        'ldflags': [ '-rdynamic' ],
        'conditions': [
          [ 'skia_fast', { 'cflags': [ '<@(skia_fast_flags)' ] }],
          [ 'skia_arch_type == "x86_64" and not skia_android_framework', {
            'cflags': [
              '-m64',
            ],
            'ldflags': [
              '-m64',
            ],
          }],
          [ 'skia_arch_type == "x86" and not skia_android_framework', {
            'cflags': [
              '-m32',
            ],
            'ldflags': [
              '-m32',
=======
          '-Wnon-virtual-dtor',
          '-Wno-invalid-offsetof',  # GCC <4.6 is old-school strict about what is POD.
        ],
        'conditions': [
          [ 'skia_fast', { 'cflags': [ '<@(skia_fast_flags)' ] }],
          [ 'skia_os != "chromeos"', {
            'conditions': [
              [ 'skia_arch_type == "x86_64" and not skia_android_framework', {
                'cflags': [
                  '-m64',
                ],
                'ldflags': [
                  '-m64',
                ],
              }],
              [ 'skia_arch_type == "x86" and not skia_android_framework', {
                'cflags': [
                  '-m32',
                ],
                'ldflags': [
                  '-m32',
                ],
              }],
>>>>>>> miniblink49
            ],
          }],
          [ 'skia_warnings_as_errors', {
            'cflags': [
              '-Werror',
            ],
          }],
          # For profiling; reveals some costs, exaggerates others (e.g. trivial setters & getters).
          [ 'skia_disable_inlining', {
            'cflags': [
              '-fno-inline',
              '-fno-default-inline',
              '-finline-limit=0',
              '-fno-omit-frame-pointer',
            ],
          }],
          [ 'skia_arch_type == "arm" and arm_version >= 7', {
            'cflags': [
              '-march=armv7-a',
              '-mthumb',
            ],
            'ldflags': [
              '-march=armv7-a',
            ],
            'conditions': [
              [ 'arm_neon == 1', {
                'defines': [
                  'SK_ARM_HAS_NEON',
                ],
                'cflags': [
                  '-mfpu=neon',
                ],
              }],
<<<<<<< HEAD
              [ 'skia_os != "linux"', {
=======
              [ 'arm_neon_optional == 1', {
                'defines': [
                  'SK_ARM_HAS_OPTIONAL_NEON',
                ],
              }],
              [ 'skia_os != "chromeos" and skia_os != "linux"', {
>>>>>>> miniblink49
                'cflags': [
                  '-mfloat-abi=softfp',
                ],
              }],
            ],
          }],
<<<<<<< HEAD
          [ '"mips" in skia_arch_type', {
            'target_conditions': [
              [ '_toolset == "target"', {
                'cflags' : ['-EL'],
                'conditions' : [
                  [ 'mips_arch_variant == "mips32r2"', {
                    'cflags': [ '-march=mips32r2' ],
                    'conditions': [
                      [ 'mips_dsp == 1', { 'cflags': [ '-mdsp'   ] }],
                      [ 'mips_dsp == 2', { 'cflags': [ '-mdspr2' ] }],
=======
          [ 'skia_arch_type == "mips"', {
            'cflags': [
              '-EL',
            ],
            'conditions': [
              [ 'mips_arch_variant == "mips32r2"', {
                'cflags': [
                  '-march=mips32r2',
                ],
                'conditions': [
                  [ 'mips_dsp == 1', {
                    'cflags': [
                      '-mdsp',
                    ],
                    'defines': [
                      'SK_MIPS_HAS_DSP',
                    ],
                  }],
                  [ 'mips_dsp == 2', {
                    'cflags': [
                      '-mdspr2',
                    ],
                    'defines': [
                      'SK_MIPS_HAS_DSP',
                      'SK_MIPS_HAS_DSPR2',
>>>>>>> miniblink49
                    ],
                  }],
                ],
              }],
            ],
          }],
        ],
      },
    ],

    ['skia_android_framework', {
<<<<<<< HEAD
=======
      'includes' : [
        'skia_for_android_framework_defines.gypi',
      ],
>>>>>>> miniblink49
      'cflags': [
        # Skia does not enforce this usage pattern so we disable it here to avoid
        # unecessary log spew when building
        '-Wno-unused-parameter',

        # Android's -D_FORTIFY_SOURCE=2 extensions are incompatibile with SkString.
        # Revert to -D_FORTIFY_SOURCE=1
        '-U_FORTIFY_SOURCE',
        '-D_FORTIFY_SOURCE=1',

<<<<<<< HEAD
        # We can't use the skia_shared_lib gyp setting because we need to
=======
        # We can't use the skia_shared_library gyp setting because we need to
>>>>>>> miniblink49
        # isolate this define to Skia sources. CFLAGS are local to Android.mk
        # and ensures that this define is not exported to clients of the library
        '-DSKIA_IMPLEMENTATION=1',
      ],
      # Remove flags which are either unnecessary or problematic for the
      # Android framework build. Many of these flags are removed simply because
      # they were not previously in the Android framework makefile, and we did
      # did not intend to add them when generating the makefile.
      # TODO (scroggo): Investigate whether any of these flags are actually
      # needed/would be beneficial.
      'cflags!': [
        # Android has one makefile, used for both debugging (after manual
        # modification) and release. Turn off debug info by default.
        '-g',
        '-march=armv7-a',
        '-mthumb',
        '-mfpu=neon',
        '-mfloat-abi=softfp',
        '-fno-exceptions',
        '-fstrict-aliasing',
        # Remove flags to turn on warnings, since most people building Android
        # are not focused on Skia and do not need the extra warning info.
        '-Wall',
        '-Wextra',
        '-Winit-self',
        '-Wpointer-arith',
        '-Wsign-compare',
      ],
      'cflags_cc!': [
        '-fno-rtti',
        '-Wnon-virtual-dtor',
      ],
      'defines': [
        'DCT_IFAST_SUPPORTED',
        # using freetype's embolden allows us to adjust fake bold settings at
        # draw-time, at which point we know which SkTypeface is being drawn
        'SK_USE_FREETYPE_EMBOLDEN',
        'SK_SFNTLY_SUBSETTER "sample/chromium/font_subsetter.h"',
        # When built as part of the system image we can enable certian non-NDK
        # compliant optimizations.
        'SK_BUILD_FOR_ANDROID_FRAMEWORK',
        # Optimizations for chromium (m30)
        'GR_GL_CUSTOM_SETUP_HEADER "gl/GrGLConfig_chrome.h"',
<<<<<<< HEAD
        'SK_DEFAULT_FONT_CACHE_LIMIT   (768 * 1024)',
        'SK_DEFAULT_GLOBAL_DISCARDABLE_MEMORY_POOL_SIZE (512 * 1024)',
        'SK_IGNORE_ETC1_SUPPORT',
        # We can't use the skia_shared_lib gyp setting because we need expose
        # this define globally and the the implemention define as a cflag.
        'SKIA_DLL',
        'SK_PRINT_CODEC_MESSAGES',
      ],
    }],

    ['skia_use_android_framework_defines', {
      # Add these defines when building for the Android framework, or when
      # specifically requested. These should be temporary staging defines. Any
      # permanent defines should be moved into the skia_android_framework block
      # above.
      'includes' : [
        'skia_for_android_framework_defines.gypi',
      ],
      'defines': [
=======
        'IGNORE_ROT_AA_RECT_OPT',
        'SK_DEFAULT_FONT_CACHE_LIMIT   (768 * 1024)',
        'SK_DEFAULT_GLOBAL_DISCARDABLE_MEMORY_POOL_SIZE (512 * 1024)',
        'SK_IGNORE_ETC1_SUPPORT',
        # We can't use the skia_shared_library gyp setting because we need expose
        # this define globally and the the implemention define as a cflag.
        'SKIA_DLL',
        'SK_PRINT_CODEC_MESSAGES',
        # Defines from skia_for_android_framework_defines.gypi
>>>>>>> miniblink49
        '<@(skia_for_android_framework_defines)',
      ],
    }],

<<<<<<< HEAD
    [ 'skia_use_sdl == 1',
      {
        'defines': [ 'SK_USE_SDL' ],
    }],

    [ 'skia_dump_stats == 1',
      {
        'defines': [ 'SK_DUMP_STATS'],
    }],

    [ 'skia_os in ["linux", "freebsd", "openbsd", "solaris"]',
=======
    [ 'skia_os in ["linux", "freebsd", "openbsd", "solaris", "chromeos"]',
>>>>>>> miniblink49
      {
        'defines': [
          'SK_SAMPLES_FOR_X',
          'SK_BUILD_FOR_UNIX',
        ],
        'configurations': {
          'Coverage': {
            'conditions': [
              [ 'skia_clang_build', {
<<<<<<< HEAD
                'cflags': ['-fprofile-instr-generate', '-fcoverage-mapping'],
=======
                'cflags': ['-fprofile-instr-generate', '-fcoverage-mapping', '-w'],
>>>>>>> miniblink49
                'ldflags': ['-fprofile-instr-generate', '-fcoverage-mapping'],
              }, {
                'cflags': ['--coverage'],
                'ldflags': ['--coverage'],
              }],
            ],
          },
          'Debug': {
          },
          'Release': {
            'cflags': [
              '-O<(skia_release_optimization_level)',
            ],
            'defines': [ 'NDEBUG' ],
          },
        },
        'conditions' : [
          [ 'skia_shared_lib', {
            'defines': [
              'SKIA_DLL',
              'SKIA_IMPLEMENTATION=1',
            ],
          }],
          # Enable asan, tsan, etc.
          [ 'skia_sanitizer', {
<<<<<<< HEAD
            'cflags_cc!': [ '-fno-rtti' ],                        # vptr needs rtti
            'cflags': [
              '-fsanitize=<(skia_sanitizer)',                     # Turn on sanitizers.
              '-fno-sanitize-recover=<(skia_sanitizer)',          # Make any failure fatal.
              '-fsanitize-blacklist=<(skia_sanitizer_blacklist)', # Compile in our blacklist.
              '-include <(skia_sanitizer_blacklist)',             # Make every .cpp depend on it.
            ],
            'ldflags': [ '-fsanitize=<(skia_sanitizer)' ],
=======
            'cflags': [
              '-fsanitize=<(skia_sanitizer)',
            ],
            'ldflags': [
              '-fsanitize=<(skia_sanitizer)',
            ],
>>>>>>> miniblink49
            'conditions' : [
              [ 'skia_sanitizer == "thread"', {
                'defines': [ 'THREAD_SANITIZER' ],
              }],
<<<<<<< HEAD
              [ 'skia_sanitizer == "memory"', {
                'cflags': [
                    '-O1',
                    '-fsanitize-memory-track-origins',
                ],
=======
              [ 'skia_sanitizer == "undefined"', {
                'cflags_cc!': ['-fno-rtti'],
>>>>>>> miniblink49
              }],
            ],
          }],
          [ 'skia_clang_build', {
            'cflags_cc': [
                '-Wno-unknown-warning-option',  # Allows unknown warnings.
                '-Wno-deprecated',              # From Qt, via debugger (older Clang).
                '-Wno-deprecated-register',     # From Qt, via debugger (newer Clang).
            ],
            'cflags': [
                # Extra warnings we like but that only Clang knows about.
                '-Wstring-conversion',
            ],
            'cflags!': [
                '-mfpmath=sse',  # Clang doesn't need to be told this, and sometimes gets confused.
            ],
          }],
          [ 'skia_keep_frame_pointer', {
            'cflags': [ '-fno-omit-frame-pointer' ],
          }],
        ],
      },
    ],

    [ 'skia_os == "mac"',
      {
        'defines': [ 'SK_BUILD_FOR_MAC' ],
<<<<<<< HEAD
        'conditions': [
            # ANGLE for mac hits -Wunneeded-internal-declaration if this isn't set.
            [ 'skia_angle', { 'defines': [ 'YY_NO_INPUT' ], } ],
        ],
=======
>>>>>>> miniblink49
        'configurations': {
          'Coverage': {
            'xcode_settings': {
               'GCC_OPTIMIZATION_LEVEL': '0',
               'GCC_GENERATE_TEST_COVERAGE_FILES': 'YES',
               'GCC_INSTRUMENT_PROGRAM_FLOW_ARCS' : 'YES',
            },
          },
          'Debug': {
            'xcode_settings': { 'GCC_OPTIMIZATION_LEVEL': '0' },
          },
          'Release': {
            'xcode_settings': { 'GCC_OPTIMIZATION_LEVEL': '<(skia_release_optimization_level)', },
            'defines': [ 'NDEBUG' ],
          },
        },
        'xcode_settings': {
          'conditions': [
            [ 'skia_fast', { 'WARNING_CFLAGS': [ '<@(skia_fast_flags)' ] } ],
            [ 'skia_warnings_as_errors', { 'GCC_TREAT_WARNINGS_AS_ERRORS': 'YES' }],
<<<<<<< HEAD
            [ 'skia_arch_type == "x86"', { 'ARCHS': ['i386']   }],
            [ 'skia_arch_type == "x86_64"', { 'ARCHS': ['x86_64'] }],
            [ 'skia_osx_deployment_target==""', {
              'MACOSX_DEPLOYMENT_TARGET': '10.7', # -mmacos-version-min, passed in env to ld.
            }, {
              'MACOSX_DEPLOYMENT_TARGET': '<(skia_osx_deployment_target)',
            }],
            [ 'skia_sanitizer', {
              'GCC_ENABLE_CPP_RTTI': 'YES',                         # vptr needs rtti
              'OTHER_CFLAGS': [
                '-fsanitize=<(skia_sanitizer)',                     # Turn on sanitizers.
                '-fno-sanitize-recover=<(skia_sanitizer)',          # Make any failure fatal.
                '-fsanitize-blacklist=<(skia_sanitizer_blacklist)', # Compile in our blacklist.
                '-include <(skia_sanitizer_blacklist)',             # Make every .cpp depend on it.
              ],
              # We want to pass -fsanitize=... to our final link call,
              # but not to libtool. OTHER_LDFLAGS is passed to both.
              # To trick GYP into doing what we want, we'll piggyback on
              # LIBRARY_SEARCH_PATHS, producing "-L/usr/lib -fsanitize=...".
              # The -L/usr/lib is redundant but innocuous: it's a default path.
              'LIBRARY_SEARCH_PATHS': [ '/usr/lib -fsanitize=<(skia_sanitizer)'],
            }],
          ],
          'CLANG_CXX_LIBRARY':                         'libc++',
          'CLANG_CXX_LANGUAGE_STANDARD':               'c++11',
          'GCC_ENABLE_CPP_EXCEPTIONS':                 'NO',   # -fno-exceptions
          'GCC_ENABLE_CPP_RTTI':                       'NO',   # -fno-rtti
          'GCC_THREADSAFE_STATICS':                    'NO',   # -fno-threadsafe-statics
          'GCC_ENABLE_SUPPLEMENTAL_SSE3_INSTRUCTIONS': 'YES',  # -mssse3
          'GCC_SYMBOLS_PRIVATE_EXTERN':                'YES',  # -fvisibility=hidden
          'GCC_INLINES_ARE_PRIVATE_EXTERN':            'YES',  # -fvisibility-inlines-hidden
          'GCC_CW_ASM_SYNTAX':                         'NO',   # remove -fasm-blocks
          'GCC_ENABLE_PASCAL_STRINGS':                 'NO',   # remove -mpascal-strings
=======
            [ 'skia_arch_width == 32', { 'ARCHS': ['i386']   }],
            [ 'skia_arch_width == 64', { 'ARCHS': ['x86_64'] }],
            [ 'skia_osx_deployment_target==""', {
              'MACOSX_DEPLOYMENT_TARGET': '10.6', # -mmacos-version-min, passed in env to ld.
            }, {
              'MACOSX_DEPLOYMENT_TARGET': '<(skia_osx_deployment_target)',
            }],
          ],
          'CLANG_CXX_LANGUAGE_STANDARD':               'c++11',
          'GCC_ENABLE_SUPPLEMENTAL_SSE3_INSTRUCTIONS': 'YES',  # -mssse3
          'GCC_SYMBOLS_PRIVATE_EXTERN':                'NO',   # -fvisibility=hidden
          'GCC_INLINES_ARE_PRIVATE_EXTERN':            'NO',   # -fvisibility-inlines-hidden
          'GCC_CW_ASM_SYNTAX':                         'NO',   # remove -fasm-blocks
          'GCC_ENABLE_PASCAL_STRINGS':                 'NO',   # remove -mpascal-strings
          'GCC_WARN_ABOUT_INVALID_OFFSETOF_MACRO':     'NO',   # -Wno-invalid-offsetof
>>>>>>> miniblink49
          'WARNING_CFLAGS': [
            '-Wall',
            '-Wextra',
            '-Winit-self',
            '-Wpointer-arith',
            '-Wsign-compare',
<<<<<<< HEAD
            '-Wvla',
=======
>>>>>>> miniblink49

            '-Wno-unused-parameter',
          ],
        },
      },
    ],

    [ 'skia_os == "ios"',
      {
        'defines': [
<<<<<<< HEAD
          # When targetting iOS and using gyp to generate the build files, it is
          # not possible to select files to build depending on the architecture
          # (i.e. it is not possible to use hand optimized assembly version). In
          # that configuration, disable all optimisation.
          'SK_BUILD_FOR_IOS',
          'SK_BUILD_NO_OPTS',
=======
          'SK_BUILD_FOR_IOS',
>>>>>>> miniblink49
        ],
        'conditions' : [
          [ 'skia_warnings_as_errors', {
            'xcode_settings': {
              'OTHER_CPLUSPLUSFLAGS': [
                '-Werror',
              ],
            },
          }],
        ],
        'configurations': {
          'Debug': {
            'xcode_settings': {
              'GCC_OPTIMIZATION_LEVEL': '0',
            },
          },
          'Release': {
            'xcode_settings': {
              'GCC_OPTIMIZATION_LEVEL': '<(skia_release_optimization_level)',
            },
            'defines': [ 'NDEBUG' ],
          },
        },
        'xcode_settings': {
          'ARCHS': ['armv7'],
          'CODE_SIGNING_REQUIRED': 'NO',
<<<<<<< HEAD
          'IPHONEOS_DEPLOYMENT_TARGET': '<(ios_sdk_version)',
          'SDKROOT': 'iphoneos',
          'TARGETED_DEVICE_FAMILY': '1,2',

          'CLANG_CXX_LIBRARY':              'libc++',
          'CLANG_CXX_LANGUAGE_STANDARD':    'c++11',
          'GCC_ENABLE_CPP_EXCEPTIONS':      'NO',   # -fno-exceptions
          'GCC_ENABLE_CPP_RTTI':            'NO',   # -fno-rtti
          'GCC_THREADSAFE_STATICS':         'NO',   # -fno-threadsafe-statics
          'GCC_SYMBOLS_PRIVATE_EXTERN':     'YES',  # -fvisibility=hidden
          'GCC_INLINES_ARE_PRIVATE_EXTERN': 'YES',  # -fvisibility-inlines-hidden

          'GCC_THUMB_SUPPORT': 'NO',  # TODO(mtklein): why would we not want thumb?
=======
          'CODE_SIGN_IDENTITY[sdk=iphoneos*]': 'iPhone Developer: Google Development (3F4Y5873JF)',
          'IPHONEOS_DEPLOYMENT_TARGET': '<(ios_sdk_version)',
          'SDKROOT': 'iphoneos',
          'TARGETED_DEVICE_FAMILY': '1,2',
          'GCC_WARN_ABOUT_INVALID_OFFSETOF_MACRO': 'NO',   # -Wno-invalid-offsetof
          'OTHER_CPLUSPLUSFLAGS': [
            '-std=c++0x',
            '-fvisibility=hidden',
            '-fvisibility-inlines-hidden',
          ],
          'GCC_THUMB_SUPPORT': 'NO',
>>>>>>> miniblink49
        },
      },
    ],

    [ 'skia_os == "android"',
      {
        'defines': [
          'SK_BUILD_FOR_ANDROID',

          # Android Text Tuning
          'SK_GAMMA_EXPONENT=1.4',
          'SK_GAMMA_CONTRAST=0.0',
        ],
        # Android defines a fixed gamma exponent instead of using SRGB
        'defines!': [
          'SK_GAMMA_SRGB',
        ],
        'configurations': {
<<<<<<< HEAD
          'Release': {
            'cflags': ['-O2'],
            'conditions': [
              [ 'skia_clang_build', {
                'cflags!': ['-g'],
                'cflags': [ '-gline-tables-only' ],
              }],
            ],
=======
          'Debug': {
            'cflags': ['-g']
          },
          'Release': {
            'cflags': ['-O2'],
>>>>>>> miniblink49
          },
        },
        'libraries': [
          '-llog',
        ],
        'cflags': [
          '-fuse-ld=gold',
        ],
        'conditions': [
          [ '"x86" in skia_arch_type', {
            'cflags': [
              '-mssse3',
            ],
          }],
          [ 'skia_android_framework', {
            'cflags!': [
              '-fuse-ld=gold',
              '-mssse3',
            ],
          }],
          [ 'skia_shared_lib', {
            'defines': [
              'SKIA_DLL',
              'SKIA_IMPLEMENTATION=1',
<<<<<<< HEAD
              # Needed until we fix https://bug.skia.org/2440 .
=======
              # Needed until we fix skbug.com/2440.
>>>>>>> miniblink49
              'SK_SUPPORT_LEGACY_CLIPTOLAYERFLAG',
            ],
          }],
          [ 'skia_profile_enabled == 1', {
            'cflags': ['-g', '-fno-omit-frame-pointer', '-marm', '-mapcs'],
          }],
<<<<<<< HEAD
          [ 'skia_clang_build', {
            'cflags': [
                '-Wno-unknown-warning-option', # Allows unknown warnings
                # These flags that are on by default for only the android
                # toolchain and no other platforms.
                '-Wno-tautological-compare',
                '-Wno-unused-command-line-argument',
            ],
          }],
=======
>>>>>>> miniblink49
        ],
      },
    ],

    [ 'skia_moz2d', {
      'defines': [
        # add flags here (e.g. SK_SUPPORT_LEGACY_...) needed by moz2d
      ],
    }],

<<<<<<< HEAD
    [ 'skia_command_buffer and skia_os == "linux"', {
      'ldflags': [
          '-Wl,-rpath,\$$ORIGIN/lib',
      ],
    }],

    [ 'skia_command_buffer and skia_os == "mac"', {
      'xcode_settings': {
          'LD_RUNPATH_SEARCH_PATHS': ['@executable_path/.'],
      },
    }],

=======
>>>>>>> miniblink49
  ], # end 'conditions'
  # The Xcode SYMROOT must be at the root. See build/common.gypi in chromium for more details
  'xcode_settings': {
    'SYMROOT': '<(DEPTH)/xcodebuild',
  },
}
