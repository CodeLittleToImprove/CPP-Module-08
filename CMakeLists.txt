cmake_minimum_required(VERSION 3.30)
project(cpp08)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # don't silently upgrade
set(CMAKE_CXX_EXTENSIONS OFF)

# Add strict warnings
#add_compile_options(-Wall -Wextra -Werror)


add_executable(CPP_08_ex00
#        ex00/Template.cpp
        ex00/main.cpp)
