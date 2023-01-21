cmake_minimum_required( VERSION 3.18 )

project( cppguilded )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED True )

set( JSON_ImplicitConversions OFF )

include(FetchContent)

FetchContent_Declare(certify GIT_REPOSITORY https://github.com/djarek/certify)
FetchContent_GetProperties(certify)
if(NOT certify_POPULATED)
    FetchContent_Populate(certify)
endif()

FetchContent_Declare(boost_beast
        GIT_REPOSITORY https://github.com/boostorg/beast
        GIT_TAG        boost-1.77.0
        )

FetchContent_Declare(nlohmann_json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.10.4
        )

FetchContent_MakeAvailable(boost_beast nlohmann_json)

include_directories( ${CMAKE_STAGING_PREFIX}/usr/include ${certify_SOURCE_DIR}/include)
link_directories( ${CMAKE_STAGING_PREFIX}/usr/lib )

FILE(GLOB PROJECT_SOURCES CPPGuilded/*.cpp CPPGuilded/library.cpp CPPGuilded/static.cpp)
FILE(GLOB PROJECT_SOURCES CPPGuilded/Classes/*.cpp)
FILE(GLOB PROJECT_HEADERS CPPGuilded/*.hpp)
FILE(GLOB PROJECT_HEADERS CPPGuilded/Classes/*.hpp)
FILE(GLOB PROJECT_HEADERS CPPGuilded/*.h)
FILE(GLOB PROJECT_HEADERS CPPGuilded/Classes/*.h)

add_library( ${PROJECT_NAME} SHARED ${PROJECT_SOURCES} ${PROJECT_HEADERS} CPPGuilded/library.cpp CPPGuilded/static.cpp)

target_include_directories( ${PROJECT_NAME} PRIVATE CPPGuilded )

if(MSVC)
    set( CMAKE_CXX_FLAGS " /MP /O2 /GL /GS /W3 /sdl /Gd /EHa " )
else(MSVC)
    set( CMAKE_CXX_FLAGS " -Wall -Wextra -Ofast " )
endif(MSVC)

find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

if(VCPKG_TOOLCHAIN)
    find_package(unofficial-sodium CONFIG REQUIRED)
    find_package(Opus CONFIG REQUIRED)

    target_link_libraries(${PROJECT_NAME}
            unofficial-sodium::sodium
            Opus::opus
            nlohmann_json::nlohmann_json
            Boost::system
            Boost::filesystem
            OpenSSL::SSL
            OpenSSL::Crypto
            #crypt32
            ZLIB::ZLIB)
else(VCPKG_TOOLCHAIN)
    target_link_libraries(${PROJECT_NAME} sodium opus Boost::system Boost::filesystem nlohmann_json::nlohmann_json ZLIB::ZLIB OpenSSL::SSL OpenSSL::Crypto)
endif(VCPKG_TOOLCHAIN)

install(TARGETS cppguilded DESTINATION lib)
install(FILES ${PROJECT_HEADERS} DESTINATION /include/cppguilded)

add_executable(tests tests/main.cpp)

target_include_directories(tests PRIVATE CPPGuilded)

if(WIN32)
    target_link_libraries(tests cppguilded)
else(WIN32)
    target_link_libraries(tests cppguilded pthread)
endif(WIN32)

install(TARGETS tests DESTINATION bin)