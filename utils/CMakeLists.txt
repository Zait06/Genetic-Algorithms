add_library(utils SHARED utils.h utils.cpp)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_LIST_DIR})