cmake_minimum_required(VERSION 3.10)
project(client)

set(CMAKE_CXX_STANDARD 17)

# Khai báo các tệp ImGui lõi và Backend cho Android/OpenGL3
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
file(GLOB IMGUI_SOURCES
    "${IMGUI_DIR}/imgui.cpp"
    "${IMGUI_DIR}/imgui_draw.cpp"
    "${IMGUI_DIR}/imgui_tables.cpp"
    "${IMGUI_DIR}/imgui_widgets.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_android.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp"
)

# Khai báo các tệp mã nguồn Client của bạn
file(GLOB CLIENT_SOURCES
    "main.cpp"
    "gui/*.cpp"
    "modules/*.cpp"
)

add_library(client SHARED ${CLIENT_SOURCES} ${IMGUI_SOURCES})

# Trỏ đường dẫn để tìm thấy cả imgui.h và imgui_impl_android.h
target_include_directories(client PRIVATE 
    ${IMGUI_DIR} 
    ${IMGUI_DIR}/backends 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Tìm các thư viện hệ thống Android cần thiết
find_library(log-lib log)
find_library(GLESv3-lib GLESv3)
find_library(EGL-lib EGL)
find_library(android-lib android)

# Liên kết tất cả lại với nhau
target_link_libraries(client ${log-lib} ${GLESv3-lib} ${EGL-lib} ${android-lib})
