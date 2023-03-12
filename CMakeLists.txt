cmake_minimum_required(VERSION 3.2)

project(GeneticAlgorithmProject)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)

add_subdirectory(src/utils)
add_subdirectory(src/gnuplot)
add_subdirectory(src/Individual)
add_subdirectory(src/Population)
add_subdirectory(external/eigen)

add_executable(GeneticAlgorithm src/main_test.cpp)

target_link_libraries(GeneticAlgorithm utils gnuplot Individual Population)