cmake_minimum_required(VERSION 2.6)
project("Ludum Dare 25")

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 0)
set(myproject_VERSION_MINOR 01)


# Compiler options
set(CMAKE_CXX_FLAGS "-Wall -Wno-write-strings")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")



configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}"
				"src/res_handler"
				"src/various")


# Define sources and executable
#set(SOURCES Core/graphics.cpp)
FILE(GLOB_RECURSE SOURCES "src/*.cpp")


set(EXECUTABLE_NAME "myproject")
add_executable(${EXECUTABLE_NAME} ${SOURCES})


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 1.6 REQUIRED system window graphics network audio)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)
