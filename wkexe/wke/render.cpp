//#include "renderD3D.h" 
//#include "renderGL.h" 
#include "renderGDI.h" 

CRender* CRender::create(RenderType type ) 
{
#if defined(RENDER_D3D_H ) 
	if (type == D3D_RENDER ) 
		return new CRenderD3D; 
#endif 
#if defined(RENDER_GL_H ) 
	if (type == GL__RENDER ) 
		return new CRenderGL; 
#endif 
#if defined(RENDER_GDI_H ) 
	return new CRenderGDI;
#endif 
	return NULL; 
} 
