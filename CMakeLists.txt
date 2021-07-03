cmake_minimum_required (VERSION 3.5)

project(opengl)
set(CMAKE_CXX_STANDARD 11)

add_executable(main
    test/main.cpp
    test/src/shader.h
	test/src/shader.cpp
    test/src/stb_image.h
)

## shader
#file(GLOB SHADER
#	"${CMAKE_CURRENT_SOURCE_DIR}/test/shader/*.fs"
#	"${CMAKE_CURRENT_SOURCE_DIR}/test/shader/*.vs"
#)
#file(COPY ${SHADER} DESTINATION ${CMAKE_BINARY_DIR}/shader/)
#
###https://qrikko.blogspot.com/2016/05/cmake-and-how-to-copy-resources-during.html?view=classic
## Scan through resource folder for updated files and copy if none existing or changed
#file (GLOB_RECURSE resources "resources/*.*")
#foreach(resource ${resources})
#	get_filename_component(filename ${resource} NAME)
#	get_filename_component(dir ${resource} DIRECTORY)
#	get_filename_component(dirname ${dir} NAME)
#
#	set (output "")
#
#	while(NOT ${dirname} STREQUAL resources)
#		get_filename_component(path_component ${dir} NAME)
#		set (output "${path_component}/${output}")
#		get_filename_component(dir ${dir} DIRECTORY)
#		get_filename_component(dirname ${dir} NAME)
#	endwhile()
#
#	set(output "${CMAKE_CURRENT_BINARY_DIR}/resources/${output}/${filename}")
#
#	add_custom_command(
#			COMMENT "Moving updated resource-file '${filename}'"
#			OUTPUT ${output}
#			DEPENDS ${resource}
#			COMMAND ${CMAKE_COMMAND} -E copy_if_different
#			${resource}
#			${output}
#	)
#	add_custom_target(${filename} ALL DEPENDS ${resource} ${output})
#
#endforeach()
###
#
## image
#file(GLOB IMAGE
#	"${CMAKE_CURRENT_SOURCE_DIR}/resources/image/*.png"
#	"${CMAKE_CURRENT_SOURCE_DIR}/resources/image/*.jpg"
#	"${CMAKE_CURRENT_SOURCE_DIR}/resources/image/*.gif"
#)
#file(COPY ${IMAGE} DESTINATION ${CMAKE_BINARY_DIR}/image/)

# Add sub directories
add_subdirectory(vendor/glad EXCLUDE_FROM_ALL)
target_link_libraries(main PRIVATE glad)
add_subdirectory(vendor/glfw EXCLUDE_FROM_ALL)
target_link_libraries(main PRIVATE glfw)
add_subdirectory(vendor/glm EXCLUDE_FROM_ALL)
target_link_libraries(main PRIVATE glm)
