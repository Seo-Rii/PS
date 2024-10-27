cmake_minimum_required(VERSION 3.28)
project(ps)

set(CMAKE_CXX_STANDARD 17)

set(NAMESPACE icpc/2024_1)
set(PROBLEM F)


add_executable(ps
        src/${NAMESPACE}/${PROBLEM}/${PROBLEM}.cpp)
