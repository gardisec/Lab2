cmake_minimum_required(VERSION 3.30)
project(Lab2)
project(Task2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Lab2 main.cpp
        Structures/Stack.cpp
        Tasks/task1.cpp
        Tasks/task3.cpp
        Structures/Set.cpp
        Structures/arr.cpp
        Structures/Pair.cpp
        Structures/list.cpp
        Tasks/task4.cpp
        Tasks/task5.cpp
        Tasks/task6.cpp
        Structures/hashMap.cpp
)

add_executable(Task2 Tasks/task2.cpp
        ForTask2/helpFuncs.cpp
        ForTask2/SetCommands.cpp
        Structures/Set.cpp
        Structures/arr.cpp
        Structures/list.cpp
        Structures/Pair.cpp
)
