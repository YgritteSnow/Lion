#pragma once

#include "../../RenderAPI/RenderAPI.h"
#include "RenderAPIImpl.h"

class RenderTarget : public RenderAPI::RenderTarget
{
public:
	RenderTarget(RenderAPI::BackBufferFormat format, unsigned int width, unsigned int height);

	virtual RenderAPI::BackBufferFormat GetFormat() const;

	virtual unsigned int GetWidth() const;

	virtual unsigned int GetHeight() const;;

	virtual void Release();

	void AddRef(); 
	
	void Resize(unsigned int width, unsigned int height);

private:
	RefCount m_refCount;
	RenderAPI::BackBufferFormat m_format;
	unsigned int m_width;
	unsigned int m_height;
};