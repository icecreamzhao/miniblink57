# Copyright 2015 Google Inc.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
# GYP for "dm" (Diamond Master, a.k.a Dungeon master, a.k.a GM 2).
{
  'include_dirs': [
    '../dm',
    '../gm',
<<<<<<< HEAD
    '../include/private',
=======
>>>>>>> miniblink49
    '../src/core',
    '../src/effects',
    '../src/images',
    '../src/lazy',
<<<<<<< HEAD
    '../src/utils',
    '../tools/debugger',
    '../tests',
=======
    '../src/pipe/utils/',
    '../src/utils',
    '../src/utils/debugger',
    '../tests',
    '../tools',
>>>>>>> miniblink49
  ],
  'dependencies': [
    'etc1.gyp:libetc1',
    'flags.gyp:flags',
    'jsoncpp.gyp:jsoncpp',
<<<<<<< HEAD
    'libpng.gyp:libpng',
    'skia_lib.gyp:skia_lib',
    'svg.gyp:svg',
    'tools.gyp:crash_handler',
    'tools.gyp:picture_utils',
    'tools.gyp:proc_stats',
    'tools.gyp:sk_tool_utils',
    'tools.gyp:url_data_manager',
=======
    'skia_lib.gyp:skia_lib',
    'svg.gyp:svg',
    'tools.gyp:crash_handler',
    'tools.gyp:proc_stats',
    'tools.gyp:sk_tool_utils',
>>>>>>> miniblink49
    'tools.gyp:timer',
    'xml.gyp:xml',
    'xps.gyp:xps',
  ],
  'includes': [
    'gmslides.gypi',
    'pathops_unittest.gypi',
    'tests.gypi',
  ],
  'sources': [
    '../dm/DM.cpp',
    '../dm/DMSrcSink.cpp',
    '../dm/DMJsonWriter.cpp',
    '../gm/gm.cpp',

<<<<<<< HEAD
    '../src/utils/SkMultiPictureDocumentReader.cpp',
    '../tools/debugger/SkDebugCanvas.cpp',
    '../tools/debugger/SkDrawCommand.cpp',
    '../tools/debugger/SkJsonWriteBuffer.cpp',
    '../tools/debugger/SkObjectParser.cpp',
    '../tools/debugger/SkOverdrawMode.h',
    '../tools/debugger/SkOverdrawMode.cpp',
=======
    '../src/pipe/utils/SamplePipeControllers.cpp',
    '../src/utils/debugger/SkDebugCanvas.cpp',
    '../src/utils/debugger/SkDrawCommand.cpp',
    '../src/utils/debugger/SkObjectParser.cpp',
>>>>>>> miniblink49
  ],
  'conditions': [
    [ 'skia_gpu == 1', {
      'dependencies': [ 'gputest.gyp:skgputest' ],
    }],
  ],
}
