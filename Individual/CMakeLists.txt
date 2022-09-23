add_library(Individual SHARED Individual.h Individual.cpp)

target_include_directories(Individual PUBLIC ${CMAKE_CURRENT_LIST_DIR})