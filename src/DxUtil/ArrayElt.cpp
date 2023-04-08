#include "DxUtil.h"

//
// Added STDCALL_API in order to use Kendall's asm dispatch. KeithH.
//

#ifdef WIN32
	#define STDCALL_API GLAPIENTRY
#else
	#define STDCALL_API
#endif


typedef void (STDCALL_API *texarray_func)( GLenum, const void * );

typedef struct {
   GLint unit;
   struct gl_client_array *array;
   texarray_func func;
} AEtexarray;

typedef void (STDCALL_API *array_func)( const void * );

typedef struct {
   struct gl_client_array *array;
   array_func func;
} AEarray;

typedef struct {
   AEtexarray texarrays[MAX_TEXTURE_COORD_UNITS + 1];
   AEarray arrays[32];
   GLuint NewState;
} AEcontext;

#define AE_CONTEXT(ctx) ((AEcontext *)(ctx)->aelt_context)

// Busted. "t" is not a set of contigous values!
//#define TYPE_IDX(t) ((t) & 0xf)
#define TYPE_IDX(t) ( (t) == GL_DOUBLE ? 7 : (t) & 7 )

static void (STDCALL_API *colorfuncs[2][8])( const void * ) = {
   { (array_func)glColor3bv,
     (array_func)glColor3ubv,
     (array_func)glColor3sv,
     (array_func)glColor3usv,
     (array_func)glColor3iv,
     (array_func)glColor3uiv,
     (array_func)glColor3fv,
     (array_func)glColor3dv },

   { (array_func)glColor4bv,
     (array_func)glColor4ubv,
     (array_func)glColor4sv,
     (array_func)glColor4usv,
     (array_func)glColor4iv,
     (array_func)glColor4uiv,
     (array_func)glColor4fv,
     (array_func)glColor4dv }
};

static void (STDCALL_API *vertexfuncs[3][8])( const void * ) = {
   { 0,
     0,
     (array_func)glVertex2sv,
     0,
     (array_func)glVertex2iv,
     0,
     (array_func)glVertex2fv,
     (array_func)glVertex2dv },

   { 0,
     0,
     (array_func)glVertex3sv,
     0,
     (array_func)glVertex3iv,
     0,
     (array_func)glVertex3fv,
     (array_func)glVertex3dv },

   { 0,
     0,
     (array_func)glVertex4sv,
     0,
     (array_func)glVertex4iv,
     0,
     (array_func)glVertex4fv,
     (array_func)glVertex4dv }
};


static void (STDCALL_API *multitexfuncs[4][8])( GLenum, const void * ) = {
   { 0,
     0,
     (texarray_func)glMultiTexCoord1svARB,
     0,
     (texarray_func)glMultiTexCoord1ivARB,
     0,
     (texarray_func)glMultiTexCoord1fvARB,
     (texarray_func)glMultiTexCoord1dvARB },

   { 0,
     0,
     (texarray_func)glMultiTexCoord2svARB,
     0,
     (texarray_func)glMultiTexCoord2ivARB,
     0,
     (texarray_func)glMultiTexCoord2fvARB,
     (texarray_func)glMultiTexCoord2dvARB },

   { 0,
     0,
     (texarray_func)glMultiTexCoord3svARB,
     0,
     (texarray_func)glMultiTexCoord3ivARB,
     0,
     (texarray_func)glMultiTexCoord3fvARB,
     (texarray_func)glMultiTexCoord3dvARB },

   { 0,
     0,
     (texarray_func)glMultiTexCoord4svARB,
     0,
     (texarray_func)glMultiTexCoord4ivARB,
     0,
     (texarray_func)glMultiTexCoord4fvARB,
     (texarray_func)glMultiTexCoord4dvARB }
};

static void (STDCALL_API *indexfuncs[8])( const void * ) = {
   0,
   (array_func)glIndexubv,
   (array_func)glIndexsv,
   0,
   (array_func)glIndexiv,
   0,
   (array_func)glIndexfv,
   (array_func)glIndexdv
};


static void (STDCALL_API *normalfuncs[8])( const void * ) = {
   (array_func)glNormal3bv,
   0,
   (array_func)glNormal3sv,
   0,
   (array_func)glNormal3iv,
   0,
   (array_func)glNormal3fv,
   (array_func)glNormal3dv,
};


/* Wrapper functions in case glSecondaryColor*EXT doesn't exist */
static void SecondaryColor3bvEXT(const GLbyte *c)
{
   _glapi_Dispatch->SecondaryColor3bvEXT(c);
}

static void SecondaryColor3ubvEXT(const GLubyte *c)
{
   _glapi_Dispatch->SecondaryColor3ubvEXT(c);
}

static void SecondaryColor3svEXT(const GLshort *c)
{
   _glapi_Dispatch->SecondaryColor3svEXT(c);
}

static void SecondaryColor3usvEXT(const GLushort *c)
{
   _glapi_Dispatch->SecondaryColor3usvEXT(c);
}

static void SecondaryColor3ivEXT(const GLint *c)
{
   _glapi_Dispatch->SecondaryColor3ivEXT(c);
}

static void SecondaryColor3uivEXT(const GLuint *c)
{
   _glapi_Dispatch->SecondaryColor3uivEXT(c);
}

static void SecondaryColor3fvEXT(const GLfloat *c)
{
   _glapi_Dispatch->SecondaryColor3fvEXT(c);
}

static void SecondaryColor3dvEXT(const GLdouble *c)
{
   _glapi_Dispatch->SecondaryColor3dvEXT(c);
}

static void (STDCALL_API *secondarycolorfuncs[8])( const void * ) = {
   (array_func) SecondaryColor3bvEXT,
   (array_func) SecondaryColor3ubvEXT,
   (array_func) SecondaryColor3svEXT,
   (array_func) SecondaryColor3usvEXT,
   (array_func) SecondaryColor3ivEXT,
   (array_func) SecondaryColor3uivEXT,
   (array_func) SecondaryColor3fvEXT,
   (array_func) SecondaryColor3dvEXT,
};


/* Again, wrapper functions in case glSecondaryColor*EXT doesn't exist */
static void FogCoordfvEXT(const GLfloat *f)
{
   _glapi_Dispatch->FogCoordfvEXT(f);
}

static void FogCoorddvEXT(const GLdouble *f)
{
   _glapi_Dispatch->FogCoorddvEXT(f);
}

static void (STDCALL_API *fogcoordfuncs[8])( const void * ) = {
   0,
   0,
   0,
   0,
   0,
   0,
   (array_func) FogCoordfvEXT,
   (array_func) FogCoorddvEXT
};



GLboolean _ae_create_context( GLcontext *ctx )
{
   if (ctx->aelt_context)
      return GL_TRUE;

   ctx->aelt_context = MALLOC( sizeof(AEcontext) );
   if (!ctx->aelt_context)
      return GL_FALSE;

   AE_CONTEXT(ctx)->NewState = ~0;
   return GL_TRUE;
}


void _ae_destroy_context( GLcontext *ctx )
{
   if ( AE_CONTEXT( ctx ) ) {
      FREE( ctx->aelt_context );
      ctx->aelt_context = 0;
   }
}


static void _ae_update_state( GLcontext *ctx )
{
   AEcontext *actx = AE_CONTEXT(ctx);
   AEtexarray *ta = actx->texarrays;
   AEarray *aa = actx->arrays;
   GLuint i;

   for (i = 0 ; i < ctx->Const.MaxTextureCoordUnits ; i++)
      if (ctx->Array.TexCoord[i].Enabled) {
	 ta->unit = i;
	 ta->array = &ctx->Array.TexCoord[i];
	 ta->func = multitexfuncs[ta->array->Size-1][TYPE_IDX(ta->array->Type)];
	 ta++;
      }

   ta->func = 0;

   if (ctx->Array.Color.Enabled) {
      aa->array = &ctx->Array.Color;
      aa->func = colorfuncs[aa->array->Size-3][TYPE_IDX(aa->array->Type)];
      aa++;
   }

   if (ctx->Array.Normal.Enabled) {
      aa->array = &ctx->Array.Normal;
      aa->func = normalfuncs[TYPE_IDX(aa->array->Type)];
      aa++;
   }

   if (ctx->Array.Index.Enabled) {
      aa->array = &ctx->Array.Index;
      aa->func = indexfuncs[TYPE_IDX(aa->array->Type)];
      aa++;
   }

   if (ctx->Array.EdgeFlag.Enabled) {
      aa->array = &ctx->Array.EdgeFlag;
      aa->func = (array_func)glEdgeFlagv;
      aa++;
   }

   if (ctx->Array.FogCoord.Enabled) {
      aa->array = &ctx->Array.FogCoord;
      aa->func = fogcoordfuncs[TYPE_IDX(aa->array->Type)];
      aa++;
   }

   if (ctx->Array.SecondaryColor.Enabled) {
      aa->array = &ctx->Array.SecondaryColor;
      aa->func = secondarycolorfuncs[TYPE_IDX(aa->array->Type)];
      aa++;
   }

   /* Must be last
    */
   if (ctx->Array.Vertex.Enabled) {
      aa->array = &ctx->Array.Vertex;
      aa->func = vertexfuncs[aa->array->Size-2][TYPE_IDX(aa->array->Type)];
      aa++;
   }

   aa->func = 0;
   actx->NewState = 0;
}


void GLAPIENTRY _ae_loopback_array_elt( GLint elt )
{
   GET_CURRENT_CONTEXT(ctx);
   AEcontext *actx = AE_CONTEXT(ctx);
   AEtexarray *ta;
   AEarray *aa;

   if (actx->NewState)
      _ae_update_state( ctx );

   for (ta = actx->texarrays ; ta->func ; ta++) {
      GLubyte *src = ta->array->BufferObj->Data
                   + (GLuint) ta->array->Ptr
                   + elt * ta->array->StrideB;
      ta->func( ta->unit + GL_TEXTURE0_ARB, src);
   }

   /* Must be last
    */
   for (aa = actx->arrays ; aa->func ; aa++) {
      GLubyte *src = aa->array->BufferObj->Data
                   + (GLuint) aa->array->Ptr
                   + elt * aa->array->StrideB;
      aa->func( src );
   }
}



void _ae_invalidate_state( GLcontext *ctx, GLuint new_state )
{
   AE_CONTEXT(ctx)->NewState |= new_state;
}
