cmake_minimum_required(VERSION 3.10)
project(client)

set(CMAKE_CXX_STANDARD 17)

# Khai báo các tệp mã nguồn của ImGui
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
file(GLOB IMGUI_SOURCES
    "${IMGUI_DIR}/imgui.cpp"
    "${IMGUI_DIR}/imgui_draw.cpp"
    "${IMGUI_DIR}/imgui_tables.cpp"
    "${IMGUI_DIR}/imgui_widgets.cpp"
)

# Khai báo các tệp mã nguồn Client của bạn
file(GLOB CLIENT_SOURCES
    "main.cpp"
    "gui/*.cpp"
    "modules/*.cpp"
)

add_library(client SHARED ${CLIENT_SOURCES} ${IMGUI_SOURCES})

# Trỏ đường dẫn để menu.cpp có thể tìm thấy imgui.h
target_include_directories(client PRIVATE ${IMGUI_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

find_library(log-lib log)
find_library(GLESv3-lib GLESv3)
find_library(EGL-lib EGL)

target_link_libraries(client ${log-lib} ${GLESv3-lib} ${EGL-lib})
