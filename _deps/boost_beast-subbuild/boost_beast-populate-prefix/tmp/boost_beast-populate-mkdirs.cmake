# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/boost_beast-src"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/boost_beast-build"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/boost_beast-subbuild/boost_beast-populate-prefix"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/boost_beast-subbuild/boost_beast-populate-prefix/tmp"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/boost_beast-subbuild/boost_beast-populate-prefix/src/boost_beast-populate-stamp"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/boost_beast-subbuild/boost_beast-populate-prefix/src"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/boost_beast-subbuild/boost_beast-populate-prefix/src/boost_beast-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/boost_beast-subbuild/boost_beast-populate-prefix/src/boost_beast-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/boost_beast-subbuild/boost_beast-populate-prefix/src/boost_beast-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
