cmake_minimum_required(VERSION 3.3)

set(THIS_TARGET NullAPI)
set(DIR_COMMON ../Common)

include_directories(
	${DIR_COMMON}/
)

set(RENDERAPI_SOURCE_FILES_COMMON
	${DIR_COMMON}/Logger.h
	${DIR_COMMON}/Logger.cpp
	${DIR_COMMON}/RenderAPI.cpp
	${DIR_COMMON}/RenderAPIExport.def
)

set(RENDERAPI_INCLUDE_FILES
	 ../../RenderAPI/RenderAPI.h
)

set(RENDERAPI_IMPL_INCLUDE_FILES
	./RenderAPIImpl.h
	 ./Device.h
	 ./Context.h
	 ./SwapChain.h
	 ./RenderTarget.h
	 ./DepthStencil.h
	 ./VertexBuffer.h
	 ./IndexBuffer.h
	 ./Texture2D.h
	 ./FXEffect.h
)

set(RENDERAPI_IMPL_SOURCE_FILES
	 ./RenderAPIImpl.cpp
	 ./Device.cpp
	 ./Context.cpp
	 ./SwapChain.cpp
	 ./RenderTarget.cpp
	 ./DepthStencil.cpp
	 ./VertexBuffer.cpp
	 ./IndexBuffer.cpp
	 ./Texture2D.cpp
	 ./FXEffect.cpp
)

source_group(include FILES ${DIR_INTERFACE})
source_group(source\\include FILES ${RENDERAPI_IMPL_INCLUDE_FILES})
source_group(source\\source FILES ${RENDERAPI_IMPL_SOURCE_FILES})
source_group(source\\common FILES ${RENDERAPI_SOURCE_FILES_COMMON})

list(APPEND ${THIS_TARGET}_SOURCE_FILES 
	${RENDERAPI_INCLUDE_FILES}
	${RENDERAPI_IMPL_INCLUDE_FILES}
	${RENDERAPI_IMPL_SOURCE_FILES}
	${RENDERAPI_SOURCE_FILES_COMMON}
)

add_library(${THIS_TARGET} SHARED ${${THIS_TARGET}_SOURCE_FILES})