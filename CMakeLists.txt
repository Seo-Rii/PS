cmake_minimum_required(VERSION 3.28)
project(ps)

set(CMAKE_CXX_STANDARD 17)

set(NAMESPACE baekjoon)
set(PROBLEM 17114)


add_executable(ps
        src/${NAMESPACE}/${PROBLEM}/${PROBLEM}.cpp)
