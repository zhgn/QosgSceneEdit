CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)

PROJECT(QosgSceneEdit)

#
# QosgSceneEdit version number
#
SET(SE_MAJOR_VERSION 0)
SET(SE_MINOR_VERSION 1)
SET(SE_BUILD_VERSION 0)
SET(SE_VERSION "${SE_MAJOR_VERSION}.${SE_MINOR_VERSION}.${SE_BUILD_VERSION}")

#
# CPack
#
#INCLUDE(InstallRequiredSystemLibraries)
SET(CPACK_PACKAGE_VENDOR "Olivier Tournaire")
SET(CPACK_PACKAGE_VERSION_MAJOR ${SE_MAJOR_VERSION})
SET(CPACK_PACKAGE_VERSION_MINOR ${SE_MINOR_VERSION})
SET(CPACK_PACKAGE_VERSION_PATCH ${SE_BUILD_VERSION})
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.GPL")
SET(CPACK_PACKAGE_VENDOR "Olivier Tournaire [olivier.tournaire@gmail.com]")
IF(WIN32)
    SET(CPACK_NSIS_URL_INFO_ABOUT "") 
    SET(CPACK_NSIS_CONTACT "olivier.tournaire@gmail.com")
    SET(CPACK_NSIS_MODIFY_PATH ON)
ENDIF(WIN32)
INCLUDE(CPack)

SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules;${CMAKE_MODULE_PATH}")

IF(WIN32)
    SET(CMAKE_DEBUG_POSTFIX "d")
	set(EXECUTABLE_TYPE)
ENDIF(WIN32)

set( CMAKE_DEBUG_POSTFIX "_d" )
set( EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin )
set( LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin )

#
# find and setup Qt4 for this project
#
FIND_PACKAGE(Qt4 REQUIRED)
FIND_PACKAGE(OpenSceneGraph REQUIRED osgUtil osgDB osgViewer osgGA)
FIND_PACKAGE(OpenGL REQUIRED)

#
#
#
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

SET(SE_EXECUTABLE_DIR ${PROJECT_BINARY_DIR}/bin )

IF(WIN32)
    SET(SE_SHARED_LIBRARY_DIR ${PROJECT_BINARY_DIR}/bin)
ELSE(WIN32)
    SET(SE_SHARED_LIBRARY_DIR ${PROJECT_BINARY_DIR}/lib)
ENDIF(WIN32)

SET(SE_STATIC_LIBRARY_DIR ${PROJECT_BINARY_DIR}/lib/static)

SET(QosgSceneEdit_EXECUTABLE_INSTALL_DIR bin)
SET(QosgSceneEdit_LIBRARY_INSTALL_DIR lib)

ADD_SUBDIRECTORY(src/QosgSceneEdit)
