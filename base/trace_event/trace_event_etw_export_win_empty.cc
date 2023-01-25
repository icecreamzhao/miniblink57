#include <stddef.h>

#include "base/command_line.h"
#include "base/logging.h"
#include "base/memory/singleton.h"
#include "base/strings/string_tokenizer.h"
#include "base/strings/utf_string_conversions.h"
#include "base/threading/platform_thread.h"
#include "base/trace_event/trace_event.h"
#include "base/trace_event/trace_event_etw_export_win.h"
#include "base/trace_event/trace_event_impl.h"

namespace base {
namespace trace_event {

    // static
    void TraceEventETWExport::DisableETWExport()
    {
        DebugBreak();
    }

    // static
    bool TraceEventETWExport::IsETWExportEnabled()
    {
        DebugBreak();
        return false;
    }

    // static
    void TraceEventETWExport::AddEvent(
        char phase,
        const unsigned char* category_group_enabled,
        const char* name,
        unsigned long long id,
        int num_args,
        const char** arg_names,
        const unsigned char* arg_types,
        const unsigned long long* arg_values,
        const std::unique_ptr<ConvertableToTraceFormat>* convertable_values)
    {
        DebugBreak();
    }

    // static
    void TraceEventETWExport::AddCompleteEndEvent(const char* name)
    {
        DebugBreak();
    }

    // static
    bool TraceEventETWExport::IsCategoryGroupEnabled(
        const char* category_group_name)
    {
        //DebugBreak();
        return false;
    }

}

}