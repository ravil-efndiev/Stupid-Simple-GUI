cmake_minimum_required(VERSION 3.10)

project(ssgui)

set(CMAKE_CXX_STANDARD 20)

add_library(ssgui STATIC
    # source files
    src/ui/Application.cpp   
    src/ui/Window.cpp   
    src/ui/General.cpp   
    src/ui/OpenGLAPI.cpp   
    src/ui/ImguiControlls.cpp   
    src/ui/Image.cpp   
    src/ui/ElementsGeneral.cpp   
    src/ui/ElementsDrags.cpp   
    src/ui/ElementsStyled.cpp   

    # dependencies
    vendor/lib/glad/glad.c
    vendor/lib/stb_image/stb_image.cpp
    vendor/modules/imgui/imgui.cpp
    vendor/modules/imgui/backends/imgui_impl_opengl3.cpp
    vendor/modules/imgui/backends/imgui_impl_glfw.cpp
    vendor/modules/imgui/imgui_demo.cpp
    vendor/modules/imgui/imgui_draw.cpp
    vendor/modules/imgui/imgui_widgets.cpp
    vendor/modules/imgui/imgui_tables.cpp
    vendor/modules/imgui/misc/cpp/imgui_stdlib.cpp
)

target_include_directories(ssgui PUBLIC
    src/
    src/ui/
    vendor/include/
    vendor/modules/imgui/
    vendor/modules/nativefiledialog/src/include/
)

target_link_libraries(ssgui 
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/lib/glfw/libglfw3.a
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/modules/nativefiledialog/build/lib/Release/x64/libnfd.a
)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS "-Wall -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -Wno-deprecated -Wno-unused-command-line-argument")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O4")
