cmake_minimum_required(VERSION 3.26.0)

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
)

add_executable(nullptr ${SOURCES})

target_include_directories(nullptr PRIVATE
    ${INCL_DIR}
)

#Libraries


include(FetchContent)

FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)

FetchContent_MakeAvailable(glm)

target_link_libraries(nullptr PRIVATE glm::glm)