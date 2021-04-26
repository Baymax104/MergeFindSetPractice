cmake_minimum_required(VERSION 3.19)
project(MergeFindSet C)

set(CMAKE_C_STANDARD 99)

add_executable(MergeFindSet main.c
        MergeByNumber.c MergeByNumber.h
        PathCompression.c PathCompression.h
        MergeByHeight.c MergeByHeight.h)