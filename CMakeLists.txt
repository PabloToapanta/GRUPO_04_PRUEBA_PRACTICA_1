cmake_minimum_required(VERSION 3.20)
project(TowerDefense_Proyecto)

set(CMAKE_CXX_STANDARD 14)

# Aquí le decimos a CLion dónde buscar los .h
include_directories(include)

# Aquí le decimos qué archivos .cpp debe compilar juntos
add_executable(TowerDefense_Proyecto
        main.cpp
        src/ListaSecuencial.cpp
)

