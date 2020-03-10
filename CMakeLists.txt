cmake_minimum_required(VERSION 3.15)
project(Rastros C)

set(CMAKE_C_STANDARD 99)

add_executable(Rastros rastros.c camada_dados.c camada_dados.h interpretador.h interpretador.c logica.c logica.h)