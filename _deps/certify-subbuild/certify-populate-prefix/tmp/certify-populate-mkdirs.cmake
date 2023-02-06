# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/certify-src"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/certify-build"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/certify-subbuild/certify-populate-prefix"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/certify-subbuild/certify-populate-prefix/tmp"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/certify-subbuild/certify-populate-prefix/src/certify-populate-stamp"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/certify-subbuild/certify-populate-prefix/src"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/certify-subbuild/certify-populate-prefix/src/certify-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/certify-subbuild/certify-populate-prefix/src/certify-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/certify-subbuild/certify-populate-prefix/src/certify-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
