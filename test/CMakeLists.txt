project(test)

# Create the executable
add_executable(${PROJECT_NAME} main.cpp)
set(CMAKE_CXX_STANDARD 11)
target_include_directories( ${PROJECT_NAME} PUBLIC
${PROJECT_SOURCE_DIR}/src
)


## solution 1
# set(TARGET_SHADER
# ${CMAKE_CURRENT_SOURCE_DIR}/shader/shader.fs,
# ${CMAKE_CURRENT_SOURCE_DIR}/shader/shader.vs
# )
# set(SHADER_BINARY
# ${CMAKE_BINARY_DIR}/shader/shader.fs,
# ${CMAKE_BINARY_DIR}/shader/shader.vs
# )
# configure_file(${CMAKE_CURRENT_SOURCE_DIR}/shader/shader.fs
#     ${CMAKE_BINARY_DIR}/shader/shader.fs COPYONLY)
# configure_file(${CMAKE_CURRENT_SOURCE_DIR}/shader/shader.vs
# 	${CMAKE_BINARY_DIR}/shader/shader.vs COPYONLY)

## solution 2 (only linux)
file(GLOB SHADER
	"${CMAKE_CURRENT_SOURCE_DIR}/shader/*.vs"
	"${CMAKE_CURRENT_SOURCE_DIR}/shader/*.fs"
	"${CMAKE_CURRENT_SOURCE_DIR}/shader/*.gs"
)
file(COPY ${SHADER} DESTINATION ${CMAKE_BINARY_DIR}/shader/)


# Link the static library from subproject1 using it's alias sub::glad
# This will cause the include directories for that target to be added to this project
target_link_libraries(${PROJECT_NAME}
	sub::glad
	glfw
)