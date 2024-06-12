cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
# set(VCPKG_TARGET_TRIPLET x64-windows)

project(opengl_test)

# set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};C:/Development/Tools/vcpkg/installed/x64-windows")

# include_directories(C:\\Development\\Tools\\vcpkg\\installed\\x64-windows\\include)
# link_directories(C:\\Development\\Tools\\vcpkg\\installed\\x64-windows\\lib)

find_package(GTest 1.14.0 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

find_package(glm CONFIG REQUIRED)

add_executable(opengl_test 
    src/app/app.cpp
    src/game/game.cpp
    src/input/input.cpp
    src/config/config.cpp
    src/managers/buffer_manager.cpp
    src/managers/glew_manager.cpp
    src/managers/glfw_manager.cpp
    src/managers/shader_manager.cpp
    src/render/renderer.cpp
)
target_link_libraries(opengl_test PRIVATE fmt::fmt)
target_link_libraries(opengl_test PRIVATE GLEW::GLEW OpenGL::GL glfw glm::glm)
