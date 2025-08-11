cmake_minimum_required(VERSION 3.31)
project(EmployeeManagementSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(EmployeeManagementSystem main.cpp workerManager.cpp
        work.cpp
        work.h
        employee.cpp
        employee.h
        manager.cpp
        manager.h
        boss.cpp
        boss.h
        test.cpp
        test.h
)
