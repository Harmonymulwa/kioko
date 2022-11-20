cmake_minimum_required(VERSION 3.23)
project(simple_shell)

set(CMAKE_C_STANDARD 90)

add_executable(simple_shell
        builtins.c environment.c execute_commands.c
        execute_file.c get_line.c history.c main.h main.c
        memory_mangment.c parser.c print.c str_to_k.c
        strings_1.c strings_2.c)