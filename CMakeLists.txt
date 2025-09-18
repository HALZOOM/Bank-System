cmake_minimum_required(VERSION 3.26)
project(Bank_System C)

set(CMAKE_C_STANDARD 17)

add_executable(Bank_System main.c
        User/UserOperations.c
        Admin/AdminOperations.c
        Admin/AdminOperations.h
        Shared/SharedFunctions.c
        Shared/SharedFunctions.h)
