# SPDX-FileCopyrightText: 2024 Podpečan Rok <podpecanrok111@gmail.com>
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(imgui_cmake VERSION 1.0.0.0)

option(IMGUI_CMAKE_BUILD_TESTS "Build the imgui_cmake test programs" OFF)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

find_package(GLEW REQUIRED)

include(FetchContent)

FetchContent_Declare(imgui
	GIT_REPOSITORY https://github.com/ocornut/imgui.git
	GIT_TAG d4ddc46e7773e9a9b68f965d007968f35ca4e09a)  # v1.89.7

SET(GLFW_BUILD_EXAMPLES OFF)
SET(GLFW_BUILD_TESTS OFF)
SET(GLFW_BUILD_DOCS OFF)
SET(GLFW_INSTALL OFF)
FetchContent_Declare(glfw
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG 7482de6071d21db77a7236155da44c172a7f6c9e)  # 3.3.8

FetchContent_Declare(glm
	GIT_REPOSITORY https://github.com/g-truc/glm.git
	GIT_TAG bf71a834948186f4097caa076cd2663c69a10e1e)  # 0.9.9.8

FetchContent_MakeAvailable(imgui glfw glm)

file(GLOB IMGUI_SRC ${imgui_SOURCE_DIR}/*.cpp)
add_library(imgui_cmake STATIC
	${IMGUI_SRC}
	${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
	${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp)
target_include_directories(imgui_cmake PUBLIC
	${PROJECT_SOURCE_DIR}/src
	${imgui_SOURCE_DIR})
target_link_libraries(imgui_cmake PUBLIC
	${OPENGL_LIBRARIES}
	glfw
	GLEW::GLEW
	glm)
target_compile_definitions(imgui_cmake PUBLIC IMGUI_USER_CONFIG=\"${CMAKE_CURRENT_SOURCE_DIR}/src/imconfig_custom.h\")

if(IMGUI_CMAKE_BUILD_TESTS)
	add_subdirectory(tests)
endif()
