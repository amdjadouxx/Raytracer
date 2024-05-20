cmake_minimum_required(VERSION 3.17)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Werror")

include_directories(./includes/Objects)
include_directories(./includes/Materials)
include_directories(./includes/)
include_directories(./src/)
include_directories(.)

add_custom_target(fclean
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_SOURCE_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_SOURCE_DIR}/cmake_install.cmake
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_SOURCE_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_SOURCE_DIR}/Makefile
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_SOURCE_DIR}/plazza
)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/plugins)

file(GLOB SOURCES "src/*.cpp" "src/Objects/*.cpp" "src/Materials/*.cpp")

add_executable(raytracer ${SOURCES} main.cpp)
target_link_libraries(raytracer dl sfml-graphics sfml-window sfml-system sfml-system GL config++)
