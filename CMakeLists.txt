cmake_minimum_required(VERSION 3.19)
project(ciaod)

set(CMAKE_CXX_STANDARD 17)

set(WORK_1.5 Tasks/1.5/fiveTask.cpp Tasks/1.5/fiveTask.h)
set(WORK_1.6 Tasks/1.6/sixTask.cpp Tasks/1.6/sixTask.h Tasks/1.6/node/List.cpp Tasks/1.6/node/List.h Tasks/1.6/node/Node.h)
set(WORK_1.7 Tasks/1.7/sevenTask.cpp Tasks/1.7/sevenTask.h Tasks/1.7/list/List.cpp Tasks/1.7/list/List.h Tasks/1.7/list/Node.h)

set(WORK_2.0 Tasks/2.0/zero2Task.cpp Tasks/2.0/zero2Task.h)
set(WORK_2.1 Tasks/2.1/first2Task.cpp Tasks/2.1/first2Task.h)
set(WORK_2.2 Tasks/2.2/second2Task.cpp Tasks/2.2/second2Task.h)
set(WORK_2.3 Tasks/2.3/third2Task.cpp Tasks/2.3/third2Task.h)
set(WORK_2.4 Tasks/2.4/fourth2Task.cpp Tasks/2.4/fourth2Task.h Tasks/2.4/tree/RBNode.h Tasks/2.4/tree/RBTree.cpp Tasks/2.4/tree/RBTree.h)
add_executable(ciaod main.cpp Utils/Utils.h Utils/Utils.cpp Tasks/Task.h Tasks/Task.cpp Tasks/1.1/firstTask.h Tasks/1.1/firstTask.cpp Tasks/1.1/matrix/matrix.h Tasks/1.1/matrix/matrix.cpp Tasks/1.2/secondTask.h Tasks/1.2/secondTask.cpp Tasks/1.3/thirdTask.h Tasks/1.3/thirdTask.cpp Tasks/1.4/fourthTask.cpp Tasks/1.4/fourthTask.h ${WORK_1.5} ${WORK_1.6} ${WORK_1.7} ${WORK_2.0} ${WORK_2.1} ${WORK_2.2} ${WORK_2.3} ${WORK_2.4})