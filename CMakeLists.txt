cmake_minimum_required(VERSION 3.11)
project(lab6)

set(CMAKE_CXX_STANDARD 14)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(LINUX ON)
    set(CMAKE_C_COMPILER gcc)
    set(CMAKE_C_FLAGS -m32)
    set(CMAKE_CXX_COMPILER g++)
    set(CMAKE_CXX_FLAGS -m32)
elseif(WIN32)
elseif(APPLE)
    set(BUILD_ARCH "-m64")
else()
    message(FATAL_ERROR "Platform is not supported")
endif()

if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm" OR CMAKE_SYSTEM_PROCESSOR MATCHES "aarch")
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(ARCH "aarch64")
    else()
        set(ARCH "arm")
    endif()
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "mips*")
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(ARCH "mips64el")
    else()
        set(ARCH "mipsel")
    endif()
else()
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(ARCH "x86_64")
    else()
        set(ARCH "x86")
    endif()
endif()

set(CMAKE_MACOSX_RPATH ON)

if ((CMAKE_GENERATOR MATCHES "Visual Studio") AND (CMAKE_GENERATOR_TOOLSET STREQUAL ""))
    message(WARNING "Visual Studio generators use the x86 host compiler by "
            "default, even for 64-bit targets. This can result in linker "
            "instability and out of memory errors. To use the 64-bit "
            "host compiler, pass -Thost=x64 on the CMake command line.")
endif()

add_executable(lab6 main.cpp book.cpp other.cpp)