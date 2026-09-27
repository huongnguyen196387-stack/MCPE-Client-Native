cmake_minimum_required(VERSION 3.22.1)
project("mcpe_client")

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/gui
    ${CMAKE_CURRENT_SOURCE_DIR}/modules
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/dobby/include
)

# Source files
file(GLOB_RECURSE SOURCES
    "main.cpp"
    "gui/*.cpp"
    "modules/*.cpp"
    "imgui/*.cpp"
    "imgui/backends/imgui_impl_android.cpp"
    "imgui/backends/imgui_impl_opengl3.cpp"
)

add_library(client SHARED ${SOURCES})

# System Libraries for Android & OpenGL ES
find_library(log-lib log)
find_library(android-lib android)
find_library(egl-lib EGL)
find_library(gles3-lib GLESv3)

target_link_libraries(client
    ${log-lib}
    ${android-lib}
    ${egl-lib}
    ${gles3-lib}
)
