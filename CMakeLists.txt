cmake_minimum_required(VERSION 3.0.0)
project(RSA_Factoring_Challenge)

include_directories(.)

add_executable(
    factors
    factors.c
    free_all_info.c
    execute_command.c
    string_functions1.c
    string_functions2.c
    add_node_end.c
)
