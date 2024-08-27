cmake_minimum_required(VERSION 3.25)
project(linked_lists)
add_executable(linked_lists main.c linked_list.c)
target_compile_options(linked_lists PRIVATE -Wall -Wextra -Werror -g)
