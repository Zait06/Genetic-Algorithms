add_library(gnuplot SHARED gnuplot.h gnuplot.cpp)

target_include_directories(gnuplot PUBLIC ${CMAKE_CURRENT_LIST_DIR})