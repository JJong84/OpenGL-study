cmake_minimum_required(VERSION 3.20)
project(learn_opengl)

set(CMAKE_CXX_STANDARD 17)
add_compile_definitions(GL_SILENCE_DEPRECATION)

# Extern - OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
message("OPENGL_INCLUDE_DIR ${OPENGL_INCLUDE_DIR}")

# Extern - glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(extern/glfw)
include_directories(extern/glfw/include)

# Extern - assimp
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_SAMPLES OFF CACHE BOOL "" FORCE)
set(ASSIMP_NO_EXPORT ON CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_OBJ_IMPORTER ON CACHE BOOL "" FORCE)
add_subdirectory(extern/assimp)
include_directories(extern/assimp/include)

# Extern - glm
set(GLM_DIR extern/glm/cmake/glm)
find_package(GLM REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})

# Extern - glad
include_directories(extern/glad/include)
add_library(glad extern/glad/src/glad.c)

# Targets
add_executable(
        learn_opengl
        main.cpp
        utils/common.cpp
        utils/common.h
        utils/default.cpp
        utils/default.h
        utils/stb_image.h
        utils/camera.cpp
        utils/camera.h
        1_hello-window/base.cpp
        1_hello-window/base.h
        2_hello-triangle/base.cpp
        2_hello-triangle/base.h
        2_hello-triangle/ex1.cpp
        2_hello-triangle/ex1.h
        2_hello-triangle/ex2.cpp
        2_hello-triangle/ex2.h
        2_hello-triangle/ex3.cpp
        2_hello-triangle/ex3.h
        3_shaders/base.cpp
        3_shaders/base.h
        4_textures/base.cpp
        4_textures/base.h
        4_textures/ex2.cpp
        4_textures/ex2.h
        4_textures/ex3.cpp
        4_textures/ex3.h
        4_textures/ex4.cpp
        4_textures/ex4.h
        5_transformations/base.cpp
        5_transformations/base.h
        5_transformations/ex1.cpp
        5_transformations/ex1.h
        5_transformations/ex2.cpp
        5_transformations/ex2.h
        6_coordinate-systems/base.cpp
        6_coordinate-systems/base.h
        7_camera/base.cpp
        7_camera/base.h
        7_camera/ex1.cpp
        7_camera/ex1.h
        7_camera/ex2.cpp
        7_camera/ex2.h
)
target_link_libraries(learn_opengl OpenGL::GL glfw assimp glad)
target_compile_definitions(learn_opengl PUBLIC GLFW_INCLUDE_NONE)