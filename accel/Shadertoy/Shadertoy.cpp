#include "Shadertoy.h"

NAMESPACE_TOPSIDE_BEGIN


INITBLOCK {
	ContextConnectorBase::RegisterDefaultFileExt<AccelSpec>(".toy");
	ContextConnectorBase::Register<AccelSpec, ShadertoyContextLoader>(".toy");
}


NAMESPACE_TOPSIDE_END
