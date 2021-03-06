cmake_minimum_required (VERSION 2.8.7)
project ("DDS")
include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -pthread")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

include_directories ("${PROJECT_SOURCE_DIR}/handlers")
add_subdirectory (handlers)

include_directories(/usr/local/include/SettingsParser)
add_library(SettingsParser /usr/local/include/SettingsParser/SettingsParser.cpp)

add_executable(DDS main.cpp)
target_link_libraries(DDS Handler ProjectHandler DrugsHandler DrugHandler SettingsParser net_static)
install (TARGETS DDS DESTINATION bin)