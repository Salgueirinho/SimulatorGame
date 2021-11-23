cmake_minimum_required(VERSION 3.20)
project(SIMULADORpoo)

set(CMAKE_CXX_STANDARD 14)

add_executable(SIMULADORpoo main.cpp comando.cpp comando.h edificio.cpp edificio.h file.cpp file.h ilha.cpp ilha.h interface.cpp interface.h menu.cpp menu.h tempo.cpp tempo.h trabalhador.cpp trabalhador.h zona.cpp zona.h)
