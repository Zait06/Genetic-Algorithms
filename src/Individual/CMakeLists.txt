add_library(Individual STATIC Individual.h Individual.cpp)

target_include_directories(Individual PUBLIC ${CMAKE_CURRENT_LIST_DIR})