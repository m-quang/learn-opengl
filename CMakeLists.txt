cmake_minimum_required (VERSION 3.5)

project(opengl)
set(CMAKE_CXX_STANDARD 11)

add_executable(main
    test/main.cpp
    test/src/shader.h
    test/src/stb_image.h
)

file(GLOB SHADER
	"${CMAKE_CURRENT_SOURCE_DIR}/test/shader/*.vs"
	"${CMAKE_CURRENT_SOURCE_DIR}/test/shader/*.fs"
	"${CMAKE_CURRENT_SOURCE_DIR}/test/shader/*.gs"
)
file(COPY ${SHADER} DESTINATION ${CMAKE_BINARY_DIR}/shader/)

# Add sub directories
#add_subdirectory(test)
add_subdirectory(vendor/glad EXCLUDE_FROM_ALL)
target_link_libraries(main PRIVATE glad)
add_subdirectory(vendor/glfw EXCLUDE_FROM_ALL)
target_link_libraries(main PRIVATE glfw)
add_subdirectory(vendor/glm EXCLUDE_FROM_ALL)
target_link_libraries(main PRIVATE glm)
#add_subdirectory(engine)