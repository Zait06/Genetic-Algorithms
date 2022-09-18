cmake_minimum_required(VERSION 3.8)

project(GeneticAlgorithmProject)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)

# Agrega un subdirectorio
add_subdirectory(gnuplot)

# Nombre_ejecutable archivo a compilar
add_executable(GeneticAlgorithm main_test.cpp)

# Agregar las librerias (Nombre_ejecutable librerias_utilizar)
target_link_libraries(GeneticAlgorithm gnuplot)