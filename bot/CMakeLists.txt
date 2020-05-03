cmake_minimum_required(VERSION 3.15)
project(Bot C)

set(CMAKE_C_STANDARD 99)

add_executable(Bot logica_bot.c lista_bot.h lista_bot.c lista_bot.h dados.c dados.h funcoes.c funcoes.h main.c)