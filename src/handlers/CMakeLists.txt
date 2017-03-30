add_library(ProjectHandler ProjectHandler.cpp)
add_library(DrugsHandler DrugsHandler.cpp)
find_package(RapidJSON)
include_directories(${RapidJSON_INCLUDE_DIRS})