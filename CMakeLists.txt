cmake_minimum_required(VERSION 3.31.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    message(STATUS "Detected Windows")
elseif(UNIX)
    message(STATUS "Detected Linux")
elseif(APPLE)
    message(STATUS "Detected MacOS")
endif()

if(MSVC)
    message(STATUS "Detected MSVC")
    add_compile_options(/W4 /MP)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Detected G++")
    add_compile_options(-Wall -Wextra)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "Detected Clang")
    add_compile_options(-Wall -Wextra)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_compile_options(
    $<$<CONFIG:Debug>:-g>
    $<$<CONFIG:Release>:-O3>
)

#Projects
project(nullptr)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)
set(SOURCES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/InputHandler.cpp
    ${SRC_DIR}/Shader.cpp
    ${SRC_DIR}/Window.cpp
)

add_executable(nullptr ${SOURCES})

target_include_directories(nullptr PRIVATE
    ${INCL_DIR}
)

#Libraries
include(FetchContent)

#OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
target_link_libraries(nullptr OpenGL::GL)

#GLM
FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)

FetchContent_MakeAvailable(glm)
target_link_libraries(nullptr glm::glm)

#GLFW
FetchContent_Declare(
	glfw
	GIT_REPOSITORY	https://github.com/glfw/glfw.git
	GIT_TAG e7ea71be039836da3a98cea55ae5569cb5eb885c
)

FetchContent_MakeAvailable(glfw)

if(WIN32)
    set(GLFW_BUILD_WIN32 ON)
elseif(UNIX)
    set(GLFW_BUILD_WAYLAND ON)
    set(GLFW_BUILD_X11 ON)
endif()

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

target_link_libraries(nullptr glfw)

#GLAD
add_subdirectory(${LIB_DIR}/glad)
target_link_libraries(nullptr glad)