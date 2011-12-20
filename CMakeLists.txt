cmake_minimum_required(VERSION 2.8)

if(BUILD_WITH_ANDROID)
  message("Platform: Android")
  
  set(CMAKE_CROSSCOMPILING TRUE)
  set(CMAKE_SYSTEM_NAME Linux)
  if(WIN32)
    set(CMAKE_C_COMPILER $ENV{TOOLCHAIN_ROOT}/bin/arm-linux-androideabi-gcc.exe)
    set(CMAKE_CXX_COMPILER $ENV{TOOLCHAIN_ROOT}/bin/arm-linux-androideabi-g++.exe)
  else()
    set(CMAKE_C_COMPILER $ENV{TOOLCHAIN_ROOT}/bin/arm-linux-androideabi-gcc)
    set(CMAKE_CXX_COMPILER $ENV{TOOLCHAIN_ROOT}/bin/arm-linux-androideabi-g++)
  endif()

  set(CMAKE_EXE_LINKER_FLAGS "-s")
  set(CMAKE_SHARED_LINKER_FLAGS "-s -Wl,--no-undefined")

  set(ANDROID TRUE)
endif()

project(IrrMob)

if(BUILD_WITH_IOS)
  message("Platform: iOS")

  set(CMAKE_OSX_SYSROOT iphoneos)
  set(CMAKE_OSX_DEPLOYMENT_TARGET "")
  set(CMAKE_OSX_ARCHITECTURES "$(ARCHS_STANDARD_32_BIT)")
  set(XCODE_ATTRIBUTE_SDKROOT iphoneos)
  set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.moqikaka.\${PRODUCT_NAME:identifier}")
  set(CMAKE_EXE_LINKER_FLAGS "-framework Foundation -framework CoreGraphics -framework QuartzCore -framework UIKit -framework OpenGLES -framework GLKit")

  set(IOS_CODE_SIGN_ID "iPhone Developer: ")

  set(IOS TRUE)
endif()

set(CMAKE_MODULE_PATH ${IrrMob_SOURCE_DIR}/CMake)
include(Config)

add_subdirectory(irrlicht)
add_subdirectory(game)
