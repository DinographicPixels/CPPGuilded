# Install script for directory: /Users/ibrahim/CLionProjects/CPPGuilded

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/ibrahim/CLionProjects/CPPGuilded/_deps/boost_beast-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/ibrahim/CLionProjects/CPPGuilded/_deps/nlohmann_json-build/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/ibrahim/CLionProjects/CPPGuilded/libcppguilded.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcppguilded.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcppguilded.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcppguilded.dylib")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/include/cppguilded/Channel.hpp;/include/cppguilded/Exceptions.hpp;/include/cppguilded/MessageHandler.hpp;/include/cppguilded/GatewayHandler.hpp;/include/cppguilded/WSManager.hpp;/include/cppguilded/Member.hpp;/include/cppguilded/Message.hpp;/include/cppguilded/RequestHandler.hpp;/include/cppguilded/Threadpool.hpp;/include/cppguilded/User.hpp;/include/cppguilded/Utils.hpp;/include/cppguilded/library.hpp;/include/cppguilded/static.hpp")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/include/cppguilded" TYPE FILE FILES
    "/Users/ibrahim/CLionProjects/CPPGuilded/CPPGuilded/Classes/Channel.hpp"
    "/Users/ibrahim/CLionProjects/CPPGuilded/CPPGuilded/Classes/Exceptions.hpp"
    "/Users/ibrahim/CLionProjects/CPPGuilded/CPPGuilded/Classes/Gateway/Events/MessageHandler.hpp"
    "/Users/ibrahim/CLionProjects/CPPGuilded/CPPGuilded/Classes/Gateway/GatewayHandler.hpp"
    "/Users/ibrahim/CLionProjects/CPPGuilded/CPPGuilded/Classes/Gateway/WSManager.hpp"
    "/Users/ibrahim/CLionProjects/CPPGuilded/CPPGuilded/Classes/Member.hpp"
    "/Users/ibrahim/CLionProjects/CPPGuilded/CPPGuilded/Classes/Message.hpp"
    "/Users/ibrahim/CLionProjects/CPPGuilded/CPPGuilded/Classes/RequestHandler.hpp"
    "/Users/ibrahim/CLionProjects/CPPGuilded/CPPGuilded/Classes/Threadpool.hpp"
    "/Users/ibrahim/CLionProjects/CPPGuilded/CPPGuilded/Classes/User.hpp"
    "/Users/ibrahim/CLionProjects/CPPGuilded/CPPGuilded/Classes/Utils.hpp"
    "/Users/ibrahim/CLionProjects/CPPGuilded/CPPGuilded/library.hpp"
    "/Users/ibrahim/CLionProjects/CPPGuilded/CPPGuilded/static.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE DIRECTORY FILES "/Users/ibrahim/CLionProjects/CPPGuilded/tests.app" USE_SOURCE_PERMISSIONS)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tests.app/Contents/MacOS/tests" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tests.app/Contents/MacOS/tests")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/ibrahim/CLionProjects/CPPGuilded"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tests.app/Contents/MacOS/tests")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/ibrahim/CLionProjects/CPPGuilded/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
