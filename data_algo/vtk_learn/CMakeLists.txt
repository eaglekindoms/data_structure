cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(VTKLearn)

set(VTK_DIR "D:\\SDK_PATH\\VTK9.1D\\lib\\cmake\\vtk-9.1")

find_package(VTK REQUIRED)

if (NOT VTK_FOUND)
    message("Skipping TextureCutQuadric: ${VTK_NOT_FOUND_MESSAGE}")
    return()
endif ()
message(STATUS "VTK_VERSION: ${VTK_VERSION}")

# Prevent a "command line is too long" failure in Windows.
#set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(V_TextureCutQuadric MACOSX_BUNDLE TextureCutQuadric.cpp)
target_link_libraries(V_TextureCutQuadric PRIVATE ${VTK_LIBRARIES})
add_executable(V_HelloWorld MACOSX_BUNDLE HelloWorld.cpp)
target_link_libraries(V_HelloWorld PRIVATE ${VTK_LIBRARIES})
# vtk_module_autoinit is needed
vtk_module_autoinit(
        TARGETS V_TextureCutQuadric V_HelloWorld
        MODULES ${VTK_LIBRARIES}
)
