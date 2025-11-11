cmake_minimum_required(VERSION 3.16)
project(program LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
    include
    include/breadlog
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:
        -O0
        -g
        -Wall
        -Wextra
        -fsanitize=address,undefined
        -fno-omit-frame-pointer
    >
    $<$<CONFIG:Release>:
        -O3
        -march=native
        -flto
        -DNDEBUG
        -Wall
        -Wextra
    >
)

target_link_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:-fsanitize=address,undefined>
)

# USE EITHER 1ST OR 2ND
# cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
# cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
#
# THEN 
# cmake --build build -j$(nproc)
# TO ACTUALLY BUILD IT