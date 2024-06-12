#ifndef RENDER_H
#define RENDER_H

#if defined(_WIN32 ) 
	#define _WIN32_WINNT 0x0520 
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
#endif 

#include "C:/mycode/miniblink/wke/wke.h" 

class CRender
{
public:
	enum RenderType
	{
		GDI_RENDER,
		D3D_RENDER,
		GL__RENDER,
	};
	static CRender* create(RenderType type);

	virtual bool init(HWND hView) = 0;
	virtual void destroy() = 0;
	virtual void resize(unsigned int w, unsigned int h) = 0;
	virtual void render(wkeWebView webView, int a_= -1 ) = 0;
};

#endif //! RENDER_H 

