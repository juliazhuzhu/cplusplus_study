
cmake_minimum_required(VERSION 3.5)

project (transaction CXX)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
endif()



add_executable(transaction main.cpp)
SET_PROPERTY(TARGET transaction PROPERTY CXX_STANDARD 11)

