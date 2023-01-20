/*
  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright (c) 2005-2012 Intel Corporation. All rights reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
  The full GNU General Public License is included in this distribution
  in the file called LICENSE.GPL.

  Contact Information:
  http://software.intel.com/en-us/articles/intel-vtune-amplifier-xe/

  BSD LICENSE

  Copyright (c) 2005-2012 Intel Corporation. All rights reserved.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of Intel Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef __JITPROFILING_H__
#define __JITPROFILING_H__

/*
 * Various constants used by functions
 */

/* event notification */
<<<<<<< HEAD
typedef enum iJIT_jvm_event {
=======
typedef enum iJIT_jvm_event
{
>>>>>>> miniblink49

    /* shutdown  */

    /*
     * Program exiting EventSpecificData NA
     */
    iJVM_EVENT_TYPE_SHUTDOWN = 2,

    /* JIT profiling  */

    /*
     * issued after method code jitted into memory but before code is executed
     * EventSpecificData is an iJIT_Method_Load
     */
<<<<<<< HEAD
    iJVM_EVENT_TYPE_METHOD_LOAD_FINISHED = 13,
=======
    iJVM_EVENT_TYPE_METHOD_LOAD_FINISHED=13,
>>>>>>> miniblink49

    /* issued before unload. Method code will no longer be executed, but code
     * and info are still in memory. The VTune profiler may capture method
     * code only at this point EventSpecificData is iJIT_Method_Id
     */
    iJVM_EVENT_TYPE_METHOD_UNLOAD_START,

    /* Method Profiling */

    /* method name, Id and stack is supplied
     * issued when a method is about to be entered EventSpecificData is
     * iJIT_Method_NIDS
     */
    iJVM_EVENT_TYPE_ENTER_NIDS = 19,

    /* method name, Id and stack is supplied
     * issued when a method is about to be left EventSpecificData is
     * iJIT_Method_NIDS
     */
    iJVM_EVENT_TYPE_LEAVE_NIDS
} iJIT_JVM_EVENT;

<<<<<<< HEAD
typedef enum _iJIT_ModeFlags {
    /* No need to Notify VTune, since VTune is not running */
    iJIT_NO_NOTIFICATIONS = 0x0000,
=======
typedef enum _iJIT_ModeFlags
{
    /* No need to Notify VTune, since VTune is not running */
    iJIT_NO_NOTIFICATIONS          = 0x0000,
>>>>>>> miniblink49

    /* when turned on the jit must call
     * iJIT_NotifyEvent
     * (
     *     iJVM_EVENT_TYPE_METHOD_LOAD_FINISHED,
     * )
     * for all the method already jitted
     */
<<<<<<< HEAD
    iJIT_BE_NOTIFY_ON_LOAD = 0x0001,
=======
    iJIT_BE_NOTIFY_ON_LOAD         = 0x0001,
>>>>>>> miniblink49

    /* when turned on the jit must call
     * iJIT_NotifyEvent
     * (
     *     iJVM_EVENT_TYPE_METHOD_UNLOAD_FINISHED,
     *  ) for all the method that are unloaded
     */
<<<<<<< HEAD
    iJIT_BE_NOTIFY_ON_UNLOAD = 0x0002,
=======
    iJIT_BE_NOTIFY_ON_UNLOAD       = 0x0002,
>>>>>>> miniblink49

    /* when turned on the jit must instrument all
     * the currently jited code with calls on
     * method entries
     */
    iJIT_BE_NOTIFY_ON_METHOD_ENTRY = 0x0004,

    /* when turned on the jit must instrument all
     * the currently jited code with calls
     * on method exit
     */
<<<<<<< HEAD
    iJIT_BE_NOTIFY_ON_METHOD_EXIT = 0x0008

} iJIT_ModeFlags;

/* Flags used by iJIT_IsProfilingActive() */
typedef enum _iJIT_IsProfilingActiveFlags {
    /* No profiler is running. Currently not used */
    iJIT_NOTHING_RUNNING = 0x0000,
=======
    iJIT_BE_NOTIFY_ON_METHOD_EXIT  = 0x0008

} iJIT_ModeFlags;


 /* Flags used by iJIT_IsProfilingActive() */
typedef enum _iJIT_IsProfilingActiveFlags
{
    /* No profiler is running. Currently not used */
    iJIT_NOTHING_RUNNING           = 0x0000,
>>>>>>> miniblink49

    /* Sampling is running. This is the default value
     * returned by iJIT_IsProfilingActive()
     */
<<<<<<< HEAD
    iJIT_SAMPLING_ON = 0x0001,

    /* Call Graph is running */
    iJIT_CALLGRAPH_ON = 0x0002
=======
    iJIT_SAMPLING_ON               = 0x0001,

      /* Call Graph is running */
    iJIT_CALLGRAPH_ON              = 0x0002
>>>>>>> miniblink49

} iJIT_IsProfilingActiveFlags;

/* Enumerator for the environment of methods*/
<<<<<<< HEAD
typedef enum _iJDEnvironmentType {
=======
typedef enum _iJDEnvironmentType
{
>>>>>>> miniblink49
    iJDE_JittingAPI = 2
} iJDEnvironmentType;

/**********************************
 * Data structures for the events *
 **********************************/

/* structure for the events:
 * iJVM_EVENT_TYPE_METHOD_UNLOAD_START
 */

<<<<<<< HEAD
typedef struct _iJIT_Method_Id {
    /* Id of the method (same as the one passed in
   * the iJIT_Method_Load struct
   */
    unsigned int method_id;

} * piJIT_Method_Id, iJIT_Method_Id;
=======
typedef struct _iJIT_Method_Id
{
   /* Id of the method (same as the one passed in
   * the iJIT_Method_Load struct
   */
    unsigned int       method_id;

} *piJIT_Method_Id, iJIT_Method_Id;

>>>>>>> miniblink49

/* structure for the events:
 * iJVM_EVENT_TYPE_ENTER_NIDS,
 * iJVM_EVENT_TYPE_LEAVE_NIDS,
 * iJVM_EVENT_TYPE_EXCEPTION_OCCURRED_NIDS
 */

<<<<<<< HEAD
typedef struct _iJIT_Method_NIDS {
    /* unique method ID */
    unsigned int method_id;

    /* NOTE: no need to fill this field, it's filled by VTune */
    unsigned int stack_id;

    /* method name (just the method, without the class) */
    char* method_name;
} * piJIT_Method_NIDS, iJIT_Method_NIDS;
=======
typedef struct _iJIT_Method_NIDS
{
    /* unique method ID */
    unsigned int       method_id;

    /* NOTE: no need to fill this field, it's filled by VTune */
    unsigned int       stack_id;

    /* method name (just the method, without the class) */
    char*              method_name;
} *piJIT_Method_NIDS, iJIT_Method_NIDS;
>>>>>>> miniblink49

/* structures for the events:
 * iJVM_EVENT_TYPE_METHOD_LOAD_FINISHED
 */

<<<<<<< HEAD
typedef struct _LineNumberInfo {
    /* x86 Offset from the beginning of the method*/
    unsigned int Offset;

    /* source line number from the beginning of the source file */
    unsigned int LineNumber;

} * pLineNumberInfo, LineNumberInfo;

typedef struct _iJIT_Method_Load {
    /* unique method ID - can be any unique value, (except 0 - 999) */
    unsigned int method_id;
=======
typedef struct _LineNumberInfo
{
  /* x86 Offset from the beginning of the method*/
  unsigned int Offset;

  /* source line number from the beginning of the source file */
  unsigned int LineNumber;

} *pLineNumberInfo, LineNumberInfo;

typedef struct _iJIT_Method_Load
{
    /* unique method ID - can be any unique value, (except 0 - 999) */
    unsigned int        method_id;
>>>>>>> miniblink49

    /* method name (can be with or without the class and signature, in any case
     * the class name will be added to it)
     */
<<<<<<< HEAD
    char* method_name;
=======
    char*               method_name;
>>>>>>> miniblink49

    /* virtual address of that method - This determines the method range for the
     * iJVM_EVENT_TYPE_ENTER/LEAVE_METHOD_ADDR events
     */
<<<<<<< HEAD
    void* method_load_address;

    /* Size in memory - Must be exact */
    unsigned int method_size;

    /* Line Table size in number of entries - Zero if none */
    unsigned int line_number_size;

    /* Pointer to the beginning of the line numbers info array */
    pLineNumberInfo line_number_table;

    /* unique class ID */
    unsigned int class_id;

    /* class file name */
    char* class_file_name;

    /* source file name */
    char* source_file_name;

    /* bits supplied by the user for saving in the JIT file */
    void* user_data;

    /* the size of the user data buffer */
    unsigned int user_data_size;

    /* NOTE: no need to fill this field, it's filled by VTune */
    iJDEnvironmentType env;

} * piJIT_Method_Load, iJIT_Method_Load;
=======
    void*               method_load_address;

    /* Size in memory - Must be exact */
    unsigned int        method_size;

    /* Line Table size in number of entries - Zero if none */
    unsigned int        line_number_size;

    /* Pointer to the beginning of the line numbers info array */
    pLineNumberInfo     line_number_table;

    /* unique class ID */
    unsigned int        class_id;

    /* class file name */
    char*               class_file_name;

    /* source file name */
    char*               source_file_name;

    /* bits supplied by the user for saving in the JIT file */
    void*               user_data;

    /* the size of the user data buffer */
    unsigned int        user_data_size;

    /* NOTE: no need to fill this field, it's filled by VTune */
    iJDEnvironmentType  env;

} *piJIT_Method_Load, iJIT_Method_Load;
>>>>>>> miniblink49

/* API Functions */
#ifdef __cplusplus
extern "C" {
#endif

#ifndef CDECL
<<<<<<< HEAD
#if defined WIN32 || defined _WIN32
#define CDECL __cdecl
#else /* defined WIN32 || defined _WIN32 */
#if defined _M_X64 || defined _M_AMD64 || defined __x86_64__
#define CDECL /* not actual on x86_64 platform */
#else /* _M_X64 || _M_AMD64 || __x86_64__ */
#define CDECL __attribute__((cdecl))
#endif /* _M_X64 || _M_AMD64 || __x86_64__ */
#endif /* defined WIN32 || defined _WIN32 */
=======
#  if defined WIN32 || defined _WIN32
#    define CDECL __cdecl
#  else /* defined WIN32 || defined _WIN32 */
#    if defined _M_X64 || defined _M_AMD64 || defined __x86_64__
#      define CDECL /* not actual on x86_64 platform */
#    else  /* _M_X64 || _M_AMD64 || __x86_64__ */
#      define CDECL __attribute__ ((cdecl))
#    endif /* _M_X64 || _M_AMD64 || __x86_64__ */
#  endif /* defined WIN32 || defined _WIN32 */
>>>>>>> miniblink49
#endif /* CDECL */

#define JITAPI CDECL

/* called when the settings are changed with new settings */
<<<<<<< HEAD
typedef void (*iJIT_ModeChangedEx)(void* UserData, iJIT_ModeFlags Flags);

int JITAPI iJIT_NotifyEvent(iJIT_JVM_EVENT event_type, void* EventSpecificData);

/* The new mode call back routine */
void JITAPI iJIT_RegisterCallbackEx(void* userdata,
    iJIT_ModeChangedEx NewModeCallBackFuncEx);
=======
typedef void (*iJIT_ModeChangedEx)(void *UserData, iJIT_ModeFlags Flags);

int JITAPI iJIT_NotifyEvent(iJIT_JVM_EVENT event_type, void *EventSpecificData);

/* The new mode call back routine */
void JITAPI iJIT_RegisterCallbackEx(void *userdata,
                                    iJIT_ModeChangedEx NewModeCallBackFuncEx);
>>>>>>> miniblink49

iJIT_IsProfilingActiveFlags JITAPI iJIT_IsProfilingActive(void);

void JITAPI FinalizeThread(void);

void JITAPI FinalizeProcess(void);

unsigned int JITAPI iJIT_GetNewMethodID(void);

#ifdef __cplusplus
}
#endif

#endif /* __JITPROFILING_H__ */
