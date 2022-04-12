cmake_minimum_required(VERSION 3.19)
project(ciaod)

set(CMAKE_CXX_STANDARD 17)

add_executable(ciaod main.cpp Utils/Utils.h Utils/Utils.cpp Tasks/Task.h Tasks/Task.cpp Tasks/firstTask/firstTask.h Tasks/firstTask/firstTask.cpp Tasks/firstTask/matrix/matrix.h Tasks/firstTask/matrix/matrix.cpp Tasks/secondTask/secondTask.h Tasks/secondTask/secondTask.cpp Tasks/thirdTask/thirdTask.h Tasks/thirdTask/thirdTask.cpp Tasks/fourthTask/fourthTask.cpp Tasks/fourthTask/fourthTask.h)
