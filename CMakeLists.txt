cmake_minimum_required(VERSION 2.6)
project("Ludum Dare 25")

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 0)
set(myproject_VERSION_MINOR 01)


# Compiler options
set(CMAKE_CXX_FLAGS "-Wall -Wno-write-strings")
set(CMAKE_C_FLAGS "-Wall -std=c99")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")




configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}"
				"src/res_handler"
				"src/particle_handler"
				"src/core"
				"src/event_handler"
				"src/game_objs"
				"src/various"
				"src/enemies")


# Define sources and executable
#set(SOURCES Core/graphics.cpp)
FILE(GLOB_RECURSE SOURCES "src/*.cpp")


set(EXECUTABLE_NAME "myproject")
add_executable(${EXECUTABLE_NAME} ${SOURCES})


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 1.6 REQUIRED system window graphics network audio)

# Add cpp-yaml
set (CPP_YAML_ROOT_DIR "libs/yaml-cpp")
include_directories("${CPP_YAML_ROOT_DIR}/include")
FILE(GLOB_RECURSE CPP_YAML_SOURCES ${CPP_YAML_ROOT_DIR}/src/*.cpp)
ADD_LIBRARY( 
	cpp-yaml
	${CPP_YAML_SOURCES}
)

# Add Chipmunk 
set (CHIPMUNK_ROOT_DIR "libs/Chipmunk-6.1.2")
include_directories("${CHIPMUNK_ROOT_DIR}/include/chipmunk")
FILE(GLOB_RECURSE CHIPMUNK_SOURCES ${CHIPMUNK_ROOT_DIR}/src/*.c)
ADD_LIBRARY( 
	chipmunk
	${CHIPMUNK_SOURCES}
)


target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} cpp-yaml chipmunk)


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)
