# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/nlohmann_json-src"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/nlohmann_json-build"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/nlohmann_json-subbuild/nlohmann_json-populate-prefix"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/nlohmann_json-subbuild/nlohmann_json-populate-prefix/tmp"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/nlohmann_json-subbuild/nlohmann_json-populate-prefix/src/nlohmann_json-populate-stamp"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/nlohmann_json-subbuild/nlohmann_json-populate-prefix/src"
  "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/nlohmann_json-subbuild/nlohmann_json-populate-prefix/src/nlohmann_json-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/nlohmann_json-subbuild/nlohmann_json-populate-prefix/src/nlohmann_json-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/ibrahim/CLionProjects/CPPGuilded/_deps/nlohmann_json-subbuild/nlohmann_json-populate-prefix/src/nlohmann_json-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()