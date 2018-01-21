
cmake_minimum_required(VERSION 3.5)

project (boost_pointer CXX)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
endif()

find_package (Boost 1.65.0 COMPONENTS system thread filesystem program_options)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})

add_executable(boost_pointer boost_test.cpp)
add_executable(asio_test asio_test.cpp)
add_executable(boost_uuid boost_uuid.cpp)
target_link_libraries(boost_pointer ${Boost_LIBRARIES})
target_link_libraries(asio_test ${Boost_LIBRARIES})
target_link_libraries(boost_uuid ${Boost_LIBRARIES})



