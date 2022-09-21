cmake_minimum_required(VERSION 3.19)
project(ciaod)

set(CMAKE_CXX_STANDARD 17)

set(WORK_5 Tasks/1.5/fiveTask.cpp Tasks/1.5/fiveTask.h)
set(WORK_6 Tasks/1.6/sixTask.cpp Tasks/1.6/sixTask.h Tasks/1.6/node/List.cpp Tasks/1.6/node/List.h Tasks/1.6/node/Node.h)
set(WORK_7 Tasks/1.7/sevenTask.cpp Tasks/1.7/sevenTask.h Tasks/1.7/list/List.cpp Tasks/1.7/list/List.h Tasks/1.7/list/Node.h)
add_executable(ciaod main.cpp Utils/Utils.h Utils/Utils.cpp Tasks/Task.h Tasks/Task.cpp Tasks/1.1/firstTask.h Tasks/1.1/firstTask.cpp Tasks/1.1/matrix/matrix.h Tasks/1.1/matrix/matrix.cpp Tasks/1.2/secondTask.h Tasks/1.2/secondTask.cpp Tasks/1.3/thirdTask.h Tasks/1.3/thirdTask.cpp Tasks/1.4/fourthTask.cpp Tasks/1.4/fourthTask.h ${WORK_5} ${WORK_6} ${WORK_7})