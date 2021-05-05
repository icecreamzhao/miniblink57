// Code generated from InspectorInstrumentation.idl

#ifndef InspectorOverridesInl_h
#define InspectorOverridesInl_h

#include "core/inspector/InspectorInstrumentation.h"

namespace blink {

namespace InspectorInstrumentation {

    CORE_EXPORT bool forcePseudoState(Element*, CSSSelector::PseudoType);
    CORE_EXPORT bool shouldWaitForDebuggerOnWorkerStart(ExecutionContext*);
    CORE_EXPORT bool shouldForceCORSPreflight(Document*);
    CORE_EXPORT bool shouldBlockRequest(LocalFrame*, const ResourceRequest&);
} // namespace InspectorInstrumentation

} // namespace blink

#endif // !defined(InspectorOverridesInl_h)
