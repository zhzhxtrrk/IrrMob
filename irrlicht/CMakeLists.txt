set(IRR_SRC_DIR source/Irrlicht)

set(BZIP2_SRC ${IRR_SRC_DIR}/bzip2/blocksort.c ${IRR_SRC_DIR}/bzip2/huffman.c ${IRR_SRC_DIR}/bzip2/crctable.c ${IRR_SRC_DIR}/bzip2/randtable.c ${IRR_SRC_DIR}/bzip2/bzcompress.c ${IRR_SRC_DIR}/bzip2/decompress.c ${IRR_SRC_DIR}/bzip2/bzlib.c)

set(PNG_SRC ${IRR_SRC_DIR}/libpng/png.c ${IRR_SRC_DIR}/libpng/pngerror.c ${IRR_SRC_DIR}/libpng/pngget.c ${IRR_SRC_DIR}/libpng/pngmem.c ${IRR_SRC_DIR}/libpng/pngread.c ${IRR_SRC_DIR}/libpng/pngrio.c ${IRR_SRC_DIR}/libpng/pngrtran.c ${IRR_SRC_DIR}/libpng/pngrutil.c ${IRR_SRC_DIR}/libpng/pngset.c ${IRR_SRC_DIR}/libpng/pngtrans.c ${IRR_SRC_DIR}/libpng/pngwio.c ${IRR_SRC_DIR}/libpng/pngwrite.c ${IRR_SRC_DIR}/libpng/pngwtran.c ${IRR_SRC_DIR}/libpng/pngwutil.c)

set(JPEG_SRC ${IRR_SRC_DIR}/jpeglib/jcapimin.c ${IRR_SRC_DIR}/jpeglib/jcapistd.c ${IRR_SRC_DIR}/jpeglib/jccoefct.c ${IRR_SRC_DIR}/jpeglib/jccolor.c ${IRR_SRC_DIR}/jpeglib/jcdctmgr.c ${IRR_SRC_DIR}/jpeglib/jchuff.c ${IRR_SRC_DIR}/jpeglib/jcinit.c ${IRR_SRC_DIR}/jpeglib/jcmainct.c ${IRR_SRC_DIR}/jpeglib/jcmarker.c ${IRR_SRC_DIR}/jpeglib/jcmaster.c ${IRR_SRC_DIR}/jpeglib/jcomapi.c ${IRR_SRC_DIR}/jpeglib/jcparam.c ${IRR_SRC_DIR}/jpeglib/jcprepct.c ${IRR_SRC_DIR}/jpeglib/jcsample.c ${IRR_SRC_DIR}/jpeglib/jctrans.c ${IRR_SRC_DIR}/jpeglib/jdapimin.c ${IRR_SRC_DIR}/jpeglib/jdapistd.c ${IRR_SRC_DIR}/jpeglib/jdatadst.c ${IRR_SRC_DIR}/jpeglib/jdatasrc.c ${IRR_SRC_DIR}/jpeglib/jdcoefct.c ${IRR_SRC_DIR}/jpeglib/jdcolor.c ${IRR_SRC_DIR}/jpeglib/jddctmgr.c ${IRR_SRC_DIR}/jpeglib/jdhuff.c ${IRR_SRC_DIR}/jpeglib/jdinput.c ${IRR_SRC_DIR}/jpeglib/jdmainct.c ${IRR_SRC_DIR}/jpeglib/jdmarker.c ${IRR_SRC_DIR}/jpeglib/jdmaster.c ${IRR_SRC_DIR}/jpeglib/jdmerge.c ${IRR_SRC_DIR}/jpeglib/jdpostct.c ${IRR_SRC_DIR}/jpeglib/jdsample.c ${IRR_SRC_DIR}/jpeglib/jdtrans.c ${IRR_SRC_DIR}/jpeglib/jerror.c ${IRR_SRC_DIR}/jpeglib/jfdctflt.c ${IRR_SRC_DIR}/jpeglib/jfdctfst.c ${IRR_SRC_DIR}/jpeglib/jfdctint.c ${IRR_SRC_DIR}/jpeglib/jidctflt.c ${IRR_SRC_DIR}/jpeglib/jidctfst.c ${IRR_SRC_DIR}/jpeglib/jidctint.c ${IRR_SRC_DIR}/jpeglib/jmemmgr.c ${IRR_SRC_DIR}/jpeglib/jmemnobs ${IRR_SRC_DIR}/jpeglib/jquant1.c ${IRR_SRC_DIR}/jpeglib/jquant2.c ${IRR_SRC_DIR}/jpeglib/jutils.c ${IRR_SRC_DIR}/jpeglib/jcarith.c ${IRR_SRC_DIR}/jpeglib/jdarith.c ${IRR_SRC_DIR}/jpeglib/jaricom.c)

file(GLOB LZMA_SRC ${IRR_SRC_DIR}/lzma/*.c ${IRR_SRC_DIR}/lzma/*.h)
file(GLOB AES_SRC ${IRR_SRC_DIR}/aesGladman/*.cpp ${IRR_SRC_DIR}/aesGladman/*.h)
file(GLOB ZLIB_SRC ${IRR_SRC_DIR}/zlib/*.c ${IRR_SRC_DIR}/zlib/*.h)
file(GLOB IRR_SRC ${IRR_SRC_DIR}/*.cpp ${IRR_SRC_DIR}/*.h)

if(IOS)
  file(GLOB MAC_SRC ${IRR_SRC_DIR}/*.m)
elseif(APPLE)
  file(GLOB MAC_SRC ${IRR_SRC_DIR}/MacOSX/*.h ${IRR_SRC_DIR}/MacOSX/*.mm)
endif()

if(ANDROID)
  set(CMAKE_C_FLAGS "-DPNG_THREAD_UNSAFE_OK -DPNG_NO_MMX_CODE -DPNG_NO_MNG_FEATURES")
  set(CMAKE_CXX_FLAGS "-pipe --no-exceptions --no-rtti --strict-aliasing")
else()
  if(WIN32)
    if(MSVC)
      set(CMAKE_C_FLAGS "/DPNG_THREAD_UNSAFE_OK /DPNG_NO_MMX_CODE /DPNG_NO_MNG_FEATURES")
      set(CMAKE_CXX_FLAGS "/D_IRR_STATIC_LIB_ /DNO_IRR_COMPILE_WITH_OGLES2_ /DNO_IRR_COMPILE_WITH_DIRECT3D_9_ /DNO_IRR_COMPILE_WITH_DIRECTINPUT_JOYSTICK_ /D_WIN32 /DWIN32 /D_WINDOWS")
    else()
      set(CMAKE_C_FLAGS "-DPNG_THREAD_UNSAFE_OK -DPNG_NO_MMX_CODE -DPNG_NO_MNG_FEATURES")
      set(CMAKE_CXX_FLAGS "-D_IRR_STATIC_LIB_ -DNO_IRR_COMPILE_WITH_OGLES2_ -pipe --no-exceptions --no-rtti --strict-aliasing -D_WIN32 -DWIN32 -D_WINDOWS -D__GNUWIN32 -D_MBCS -D_USRDLL")
    endif()
  else()
    set(CMAKE_C_FLAGS "-DPNG_THREAD_UNSAFE_OK -DPNG_NO_MMX_CODE -DPNG_NO_MNG_FEATURES")
  	set(CMAKE_CXX_FLAGS "-DNO_IRR_COMPILE_WITH_OGLES2_ -pipe")
  endif()
endif()

include_directories(include ${IRR_SRC_DIR} ${IRR_SRC_DIR}/MacOSX ${IRR_SRC_DIR}/libpng ${IRR_SRC_DIR}/zlib ${IRR_SRC_DIR}/jpeglib)  

if(APPLE)
	set_source_files_properties(${MAC_SRC} ${IRR_SRC} PROPERTIES
		COMPILE_FLAGS "-x objective-c++")
endif()

set(SOURCES ${IRR_SRC} ${MAC_SRC} ${PNG_SRC} ${JPEG_SRC} ${AES_SRC} ${ZLIB_SRC} ${LZMA_SRC} ${BZIP2_SRC})
irrmob_add_library(irrlicht STATIC SOURCES)

