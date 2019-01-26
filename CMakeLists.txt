cmake_minimum_required(VERSION 3.13)
project(SqList_Chain C)

set(CMAKE_C_STANDARD 99)

add_executable(SqList_Chain main.c SqList.c TestSqList.c)