cmake_minimum_required(VERSION 3.10)

project(ssgui_test)

set(CMAKE_CXX_STANDARD 20)

add_executable(ssgui_test
    src/TestApp.cpp
)

target_include_directories(ssgui_test PUBLIC
    src/
    ../src/
    ../vendor/modules/imgui/
    ../vendor/modules/nativefiledialog/src/include/
)

target_link_libraries(ssgui_test 
    ${CMAKE_CURRENT_SOURCE_DIR}/../build/libssgui.a 
    ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/lib/glfw/libglfw3.a
    ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/modules/nativefiledialog/build/lib/Release/x64/libnfd.a
)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

set(CMAKE_BUILD_TYPE Release)

if(APPLE)
    set(CMAKE_CXX_FLAGS "-Wall -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -Wno-deprecated -Wno-unused-command-line-argument")
elseif(LINUX) 
    set(CMAKE_CXX_FLAGS "-Wall -Wno-deprecated -Wno-unused-command-line-argument")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O4")
