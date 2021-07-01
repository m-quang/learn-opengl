# Set the project name
project (glad)

# Add a library with the above sources
add_library(${PROJECT_NAME} src/glad.c)
add_library(sub::glad ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)