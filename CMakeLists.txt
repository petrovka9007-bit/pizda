cmake_minimum_required(VERSION 3.28)
include(FetchContent)

project(pizda)
file(GLOB_RECURSE SOURCES
	src/*.cpp
	src/*.h
)
set(CMAKE_CXX_STANDARD 17)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

source_group(TREE ${CMAKE_SOURCE_DIR}/src FILES ${SOURCES})

if(WIN32)
	set(extra WIN32)
endif()

add_executable(zalupa ${extra} ${SOURCES})

set(RAYLIB_VERSION 5.5)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
  URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
FetchContent_MakeAvailable(raylib)

#FetchContent_Declare(
#        imgui
#        GIT_REPOSITORY https://github.com/ocornut/imgui.git
#        GIT_TAG v1.90.5
#		SOURCE_DIR ${CMAKE_SOURCE_DIR}/third_party/imgui/imgui
#)

#FetchContent_MakeAvailable(imgui)

#file(GLOB IMGUI_SRC
#  ${imgui_SOURCE_DIR}/*.h
#  ${imgui_SOURCE_DIR}/*.cpp
#  ${imgui_SOURCE_DIR}/backends/*glfw*.h
#  ${imgui_SOURCE_DIR}/backends/*glfw*.cpp
#  ${imgui_SOURCE_DIR}/backends/*opengl3*.h
#  ${imgui_SOURCE_DIR}/backends/*opengl3*.cpp
#)

#add_library(imguiLib STATIC ${IMGUI_SRC})
#target_include_directories(imguiLib
#	PRIVATE ${imgui_SOURCE_DIR}
#	INTERFACE ${CMAKE_SOURCE_DIR}/third_party/imgui/imgui
#)

target_include_directories(zalupa PRIVATE
	src
)

target_link_libraries(zalupa PRIVATE
	raylib
	#imguiLib
)

target_compile_features(zalupa PRIVATE cxx_std_17)

set_property(TARGET zalupa PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

if(WIN32)
	target_compile_definitions(zalupa PRIVATE WIN_APP)
endif()
