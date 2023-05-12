cmake_minimum_required( VERSION 3.18 )

project(CPPGuilded VERSION 1.0.0 DESCRIPTION "A library for interfacing with Guilded, using C++.")

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED True )

set( JSON_ImplicitConversions OFF )

find_package(sodium CONFIG)
find_package(unofficial-sodium CONFIG)
find_package(Opus CONFIG)
find_package(nlohmann_json CONFIG)
find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

include(FetchContent)

FetchContent_Declare(certify GIT_REPOSITORY https://github.com/djarek/certify)
FetchContent_GetProperties(certify)
if(NOT certify_POPULATED)
    FetchContent_Populate(certify)
endif()

if (NOT boost_beast_FOUND)
    message("Fetching boost_beast from source..")
    FetchContent_Declare(boost_beast GIT_REPOSITORY https://github.com/boostorg/beast GIT_TAG boost-1.77.0)
    FetchContent_MakeAvailable(boost_beast)
endif()

if(NOT sodium_FOUND AND NOT unofficial-sodium_FOUND)
    message("Fetching sodium from source..")
    FetchContent_Declare(sodium GIT_REPOSITORY https://github.com/robinlinden/libsodium-cmake.git GIT_TAG f568ff02f1bed155ea598c0e803ef3c9db2703d2)
    set(SODIUM_DISABLE_TESTS ON)
    FetchContent_MakeAvailable(sodium)
endif()

if(NOT Opus_FOUND)
    message("Fetching Opus from source..")
    FetchContent_Declare(Opus GIT_REPOSITORY https://github.com/xiph/opus)
    FetchContent_MakeAvailable(Opus)
endif()

if(NOT nlohmann_json_FOUND)
    message("Fetching nlohmann_json from source..")
    FetchContent_Declare(nlohmann_json GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent GIT_TAG v3.10.4)
    FetchContent_MakeAvailable(nlohmann_json)
endif()

include(ExternalProject)

if (NOT OpenSSL_FOUND)
    message("Fetching OpenSSL from source..")
    FetchContent_Declare(
            ssl_content
            GIT_REPOSITORY https://github.com/janbar/openssl-cmake.git
            GIT_TAG "1.1.1k-20210430"
    )
    FetchContent_MakeAvailable(ssl_content)
    add_library(OpenSSL::SSL ALIAS ssl)
    add_library(OpenSSL::Crypto ALIAS crypto)
endif()

if (NOT Boost_FOUND OR NOT ZLIB_FOUND)

if(NOT Boost_FOUND)
    message("Fetching boost from source..")
    FetchContent_Declare(Boost GIT_REPOSITORY https://github.com/boostorg/boost GIT_TAG boost-1.77.0)
    FetchContent_MakeAvailable(Boost)
endif()

if (NOT ZLIB_FOUND)
    message("Fetching ZLIB from source..")
    FetchContent_Declare(ZLIB GIT_REPOSITORY https://github.com/madler/zlib GIT_TAG v1.2.11)
    FetchContent_MakeAvailable(ZLIB)
endif()
    #set(Boost_USE_STATIC_LIBS ON)
    find_package(Boost REQUIRED COMPONENTS system filesystem)
endif()

if (NOT VCPKG_TOOLCHAIN)
    find_package(Boost COMPONENTS system filesystem REQUIRED)
    find_package(OpenSSL REQUIRED)
    find_package(ZLIB REQUIRED)
endif()

include_directories( ${CMAKE_STAGING_PREFIX}/usr/include ${certify_SOURCE_DIR}/include)
link_directories( ${CMAKE_STAGING_PREFIX}/usr/lib )

FILE(GLOB PROJECT_SOURCES CPPGuilded/*.cpp CPPGuilded/library.cpp CPPGuilded/static.cpp)
FILE(GLOB PROJECT_SOURCES CPPGuilded/Classes/*.cpp)
FILE(GLOB PROJECT_HEADERS CPPGuilded/*.hpp)
FILE(GLOB PROJECT_HEADERS CPPGuilded/Classes/*.hpp)
FILE(GLOB PROJECT_HEADERS CPPGuilded/*.h)
FILE(GLOB PROJECT_HEADERS CPPGuilded/Classes/*.h)
FILE(GLOB_RECURSE PROJECT_SOURCES CPPGuilded/*.cpp)
FILE(GLOB_RECURSE PROJECT_HEADERS CPPGuilded/*.hpp)

add_library( ${PROJECT_NAME} SHARED ${PROJECT_SOURCES} ${PROJECT_HEADERS} CPPGuilded/library.cpp CPPGuilded/static.cpp)

target_include_directories( ${PROJECT_NAME} PRIVATE CPPGuilded )

if(MSVC)
    set( CMAKE_CXX_FLAGS " /MP /O2 /GL /GS /W3 /sdl /Gd /EHa -pthread " )
else(MSVC)
    set( CMAKE_CXX_FLAGS " -Wall -Wextra -Ofast -pthread " )
endif(MSVC)

if (VCPKG_TOOLCHAIN)
target_link_libraries(${PROJECT_NAME}
        unofficial-sodium::sodium
        Opus::opus
        nlohmann_json::nlohmann_json
        Boost::system
        Boost::filesystem
        OpenSSL::SSL
        OpenSSL::Crypto
        #crypt32
        ZLIB::ZLIB
        )
elseif(NOT VCPKG_TOOLCHAIN)
    target_link_libraries(${PROJECT_NAME}
            sodium
            Opus::opus
            nlohmann_json::nlohmann_json
            Boost::system
            Boost::filesystem
            OpenSSL::SSL
            OpenSSL::Crypto
            ZLIB::ZLIB
            )
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${PROJECT_HEADERS} DESTINATION include/CPPGuilded)

# WIN32 MACOSX_BUNDLE
add_executable(tests MACOSX_BUNDLE WIN32 tests/main.cpp)

target_include_directories(tests PRIVATE CPPGuilded)

if(WIN32)
    target_link_libraries(tests CPPGuilded)
else(WIN32)
    target_link_libraries(tests CPPGuilded pthread)
endif(WIN32)

install(TARGETS tests DESTINATION bin)