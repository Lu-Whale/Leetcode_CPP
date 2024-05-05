cmake_minimum_required(VERSION 3.28)
project(Leetcode_CPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(Leetcode_CPP Practice/grammar.cpp
        FileNameGenerator.cpp
        Daily_Question/_165_Compare_Version_Numbers.cpp
        Daily_Question/_881_Boats_to_Save_People.cpp
        Daily_Question/_237_Delete_Node_in_a_Linked_List.cpp)
