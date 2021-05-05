
#include "base/logging.h"

#include <windows.h>

namespace logging {

bool ShouldCreateLogMessage(int severity)
{
    return false;
}

}