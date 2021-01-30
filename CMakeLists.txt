cmake_minimum_required(VERSION 3.19)

project(money_envelope)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_DISABLE_PRECOMPILE_HEADERS ON)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_subdirectory(lib)
add_subdirectory(utils)
add_subdirectory(money_to_cases)
add_subdirectory(test)
add_subdirectory(slon_version)

set_property (DIRECTORY PROPERTY VS_STARTUP_PROJECT money_to_cases) 
