#ifndef _Oulu_Oulu_h_
#define _Oulu_Oulu_h_

#include "Before.h"

#ifdef flagALTCORE
	#include <CoreAlt/Core.h>
	#include <DrawAlt/Draw.h>
	#define IML_HEADER <DrawAlt/iml_header.h>
	#define IML_SOURCE <DrawAlt/iml_source.h>
#else
	#include <algorithm>
	#include <Core/Core.h>
	#include <Draw/Draw.h>
	#include <plugin/bz2/bz2.h>
	#define IML_HEADER <Draw/iml_header.h>
	#define IML_SOURCE <Draw/iml_source.h>
#endif
#undef Complex


#ifdef flagDEBUG_AUDIO
	#define DEBUG_AUDIO_PIPE 1
	#define AUDIOLOG(x) LOG("AUDIO DEBUG: " << x)
#else
	#define DEBUG_AUDIO_PIPE 0
	#define AUDIOLOG(x)
#endif


NAMESPACE_OULU_BEGIN
using namespace Upp;
NAMESPACE_OULU_END


#include "Compat.h"
#include "Types.h"
#include "Recycler.h"
#include "LinkedList.h"
#include "TypeTraits.h"
#include "Visitor.h"
#include "Ref.h"
#include "Exchange.h"
#include "Interface.h"
#include "Index.h"
#include <CoreAlt/Container.h>
#include "Container.h"
#include "RTuple.h"
#include <CoreAlt/Shared.h>
#include "Util.h"
#include "Process.h"
#include "Heap.h"
#include "Math.h"
#include "Crypto.h"
#include "Neural.h"
#include "CLI.h"
#include "DCT.h"
#include "GeneticOptimizer.h"
#include "Version.h"
#include "Coordinate.h"
#include "ECS.h"
#include "Tokenizer.h"
#include "Upp.h"
#include "FFT.h"
#include "Color.h"
#include "UnitTest.h"
#include "Image.h"
#include "Geom.h"
#include "Realtime.h"
#include "Audio.h"
#include "SystemAudio.h"
#include "Video.h"
#include "Media.h"
#include "Html.h"
#include "Url.h"
#include "Debugging.h"


#endif
