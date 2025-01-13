cmake_minimum_required(VERSION 3.10)
project(yuvDemo-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

file(GLOB SOURCES "*.cpp")

add_executable(yuvDemo-cpp ${SOURCES})

target_link_libraries(yuvDemo-cpp Qt5::Core Qt5::Widgets)

target_include_directories(yuvDemo-cpp PRIVATE ${PROJECT_SOURCE_DIR})
