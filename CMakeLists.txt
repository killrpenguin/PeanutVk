cmake_minimum_required(VERSION 3.19...4.10)

project(
  PeanutVk
  VERSION 1.0
  DESCRIPTION ""
  LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  set(CMAKE_CXX_COMPILER "/usr/lib/llvm/21/bin/clang++")
  set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  set(CMAKE_CXX_EXTENSIONS OFF)

endif()

include(FetchContent)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master)

FetchContent_MakeAvailable(fmtlib)


FetchContent_Declare( stb
	GIT_REPOSITORY https://github.com/nothings/stb.git
	GIT_TAG master
	GIT_PROGRESS TRUE
	SOURCE_DIR "${CMAKE_SOURCE_DIR}/stb_image"
)

FetchContent_MakeAvailable(stb)

add_library(stb_image INTERFACE)

target_include_directories(stb_image INTERFACE ${stb_SOURCE_DIR})

# The compiled library code is here
add_subdirectory(src)
add_subdirectory(imgui)

# The executable code is here
add_subdirectory(apps)
