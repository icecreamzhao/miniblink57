
#include "base/logging.h"

#include <windows.h>

namespace logging {

std::ostream* g_swallow_stream = nullptr;

bool ShouldCreateLogMessage(int severity)
{
    return false;
}

}