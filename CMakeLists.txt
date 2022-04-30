cmake_minimum_required(VERSION 3.19)
project(ciaod)

set(CMAKE_CXX_STANDARD 17)

set(WORK_5 Tasks/fiveTask/fiveTask.cpp Tasks/fiveTask/fiveTask.h)
set(WORK_6 Tasks/sixTask/sixTask.cpp Tasks/sixTask/sixTask.h Tasks/sixTask/node/List.cpp Tasks/sixTask/node/List.h Tasks/sixTask/node/Node.h)
add_executable(ciaod main.cpp Utils/Utils.h Utils/Utils.cpp Tasks/Task.h Tasks/Task.cpp Tasks/firstTask/firstTask.h Tasks/firstTask/firstTask.cpp Tasks/firstTask/matrix/matrix.h Tasks/firstTask/matrix/matrix.cpp Tasks/secondTask/secondTask.h Tasks/secondTask/secondTask.cpp Tasks/thirdTask/thirdTask.h Tasks/thirdTask/thirdTask.cpp Tasks/fourthTask/fourthTask.cpp Tasks/fourthTask/fourthTask.h ${WORK_5} ${WORK_6})