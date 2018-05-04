
cmake_minimum_required(VERSION 3.5)

project (bridge CXX)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
endif()



add_executable(bridge main.cpp)
SET_PROPERTY(TARGET bridge PROPERTY CXX_STANDARD 11)

