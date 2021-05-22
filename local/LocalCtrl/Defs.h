#ifndef _LocalCtrl_Defs_h_
#define _LocalCtrl_Defs_h_


#ifndef flagGUI
	#error <LocalCtrl/LocalCtrl.h> should only be included, when GUI flag is set.
#endif

#ifdef flagWIN32
	#define GLEW_STATIC 1
	#include <ports/glew/glew.h>
#else
	#include <GL/glew.h>
#endif

#if HAVE_GLUT
	#include <GL/freeglut.h>
#endif


#include <Local/Local.h>

#include <CtrlLib/CtrlLib.h>
#if defined flagGUI && defined flagCTRL
	#include <SDL2GUI3D/SDL2GUI3D.h>
#endif


#endif
