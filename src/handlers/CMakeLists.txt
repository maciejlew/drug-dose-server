add_library(VersionHandler VersionHandler.cpp)
find_package(RapidJSON)
include_directories(${RapidJSON_INCLUDE_DIRS})