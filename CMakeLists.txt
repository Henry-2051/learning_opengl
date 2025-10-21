cmake_minimum_required(VERSION 3.5)
project(minimal_gl_example
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD      17)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)  
set(CMAKE_CXX_EXTENSIONS    OFF)  

#————————————————————————————
# Find OpenGL
find_package(OpenGL REQUIRED)

#————————————————————————————
# Find GLEW
# CMake ships a FindGLEW module on most distros,
# otherwise you can install glew via your package manager.
find_package(GLEW REQUIRED)

#————————————————————————————
# Find GLFW (alternatively via pkg-config)
# if your CMake has a Findglfw3.cmake you can:
find_package(glfw3 3.2 REQUIRED)

# or, if you don’t have a CMake module for glfw3, you can fall back
# to pkg‐config:
# find_package(PkgConfig REQUIRED)
# pkg_check_modules(GLFW REQUIRED glfw3)
# include_directories(${GLFW_INCLUDE_DIRS})
# link_directories(   ${GLFW_LIBRARY_DIRS})

#————————————————————————————
# Our executable
add_executable(minimal src/main.cpp)

#————————————————————————————
# Include directories
target_include_directories(minimal PRIVATE
  ${OPENGL_INCLUDE_DIR}
  ${GLEW_INCLUDE_DIRS}
  # if using pkg-config, also ${GLFW_INCLUDE_DIRS}
)

#————————————————————————————
# Link libraries
target_link_libraries(minimal PRIVATE
  OpenGL::GL           # or ${OPENGL_gl_LIBRARY}
  GLEW::GLEW           # or ${GLEW_LIBRARIES}
  glfw                 # or glfw3::glfw (depending on your find_package)
  # if using pkg-config: ${GLFW_LIBRARIES}
)

#————————————————————————————
# Install
install(TARGETS minimal RUNTIME DESTINATION bin)
