cmake_minimum_required(VERSION 3.10)
project(MiniProjetC)

add_executable(calculator calculator.cpp)
add_executable(hello_world hello_world.cpp)
add_executable(convertissor convertissor.cpp)
add_executable(guess_nbr guess_nbr.cpp)

# Version minimale de CMake requise
# cmake_minimum_required(VERSION 3.10)

# # Nom du projet + langage(s)
# project(MonProjet LANGUAGES CXX)

# Indiquer la version de C++ à utiliser
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fichiers source et création de l’exécutable
# add_executable(mon_programme main.cpp utils.cpp)
# cmake -G "MinGW Makefiles" .
