cmake_minimum_required(VERSION 3.25)
project(binary_tree)
add_executable(binary_tree main.c binary_tree.c)
target_compile_options(binary_tree PRIVATE -Wall -Wextra -Werror -g)
