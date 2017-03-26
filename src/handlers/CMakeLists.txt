add_library(ProjectHandler ProjectHandler.cpp)
find_package(RapidJSON)
include_directories(${RapidJSON_INCLUDE_DIRS})