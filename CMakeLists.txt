cmake_minimum_required(VERSION 3.31)

set(CMAKE_CXX_STANDARD 14)

add_executable(seqListStatic src/DS/code/linearList/seqListStatic.cpp)

add_executable(seqListDynamic src/DS/code/linearList/seqListDynamic.cpp)

add_executable(linkListHeadless src/DS/code/linearList/linkListHeadless.cpp)

add_executable(linkList src/DS/code/linearList/linkList.cpp)

add_executable(DLinkList src/DS/code/linearList/DLinkList.cpp)