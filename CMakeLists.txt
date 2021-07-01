cmake_minimum_required (VERSION 3.5)

project(subprojects)
set(CMAKE_CXX_STANDARD 11)

# Add sub directories
add_subdirectory(test)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)
#add_subdirectory(engine)