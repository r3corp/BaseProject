cmake_minimum_required(VERSION 3.20)
project(CPPProjectLayered)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

# definne build type
#set(CMAKE_BUILD_TYPE Release)

#include directories
include_directories("/usr/include/**")
include_directories("/usr/local/include/**")
include_directories(${SQLITE3_INCLUDE_DIRS})

# Ativar warnings
add_compile_options(-Wall -Wextra -Wpedantic)

# Incluir subdiretórios
add_subdirectory(src)
add_subdirectory(tests)

