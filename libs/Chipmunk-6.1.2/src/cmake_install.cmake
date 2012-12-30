# Install script for directory: /home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/src

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libchipmunk.so.6.1.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libchipmunk.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    ENDIF()
  ENDFOREACH()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/src/libchipmunk.so.6.1.2"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/src/libchipmunk.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libchipmunk.so.6.1.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libchipmunk.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/src/libchipmunk.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/chipmunk" TYPE FILE FILES
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/cpSpace.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/cpSpatialIndex.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/cpPolyShape.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/cpBody.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/cpShape.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/cpBB.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/chipmunk.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/cpArbiter.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/chipmunk_unsafe.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/chipmunk_types.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/cpVect.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/chipmunk_private.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/chipmunk_ffi.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/chipmunk/constraints" TYPE FILE FILES
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/constraints/cpPinJoint.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/constraints/cpSimpleMotor.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/constraints/cpRotaryLimitJoint.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/constraints/cpConstraint.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/constraints/cpDampedRotarySpring.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/constraints/cpGearJoint.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/constraints/cpSlideJoint.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/constraints/cpPivotJoint.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/constraints/cpDampedSpring.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/constraints/util.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/constraints/cpRatchetJoint.h"
    "/home/anders/Documents/Programming/ld25/libs/Chipmunk-6.1.2/include/chipmunk/constraints/cpGrooveJoint.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

