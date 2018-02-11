
cmake_minimum_required(VERSION 3.5)

project (boost_pointer CXX)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
endif()

find_package (Boost 1.65.0 COMPONENTS system thread filesystem program_options)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})

#add_executable(boost_pointer boost_test.cpp)
add_executable(asio_test asio_test.cpp)
add_executable(boost_uuid boost_uuid.cpp)
#target_link_libraries(boost_pointer ${Boost_LIBRARIES})
target_link_libraries(asio_test ${Boost_LIBRARIES})
target_link_libraries(boost_uuid ${Boost_LIBRARIES})

add_executable(test_bind test_bind.cpp)
SET_PROPERTY(TARGET test_bind PROPERTY CXX_STANDARD 11)
target_link_libraries(test_bind dl pthread)

add_executable(test_iterator test_iterator.cpp)
SET_PROPERTY(TARGET test_iterator PROPERTY CXX_STANDARD 11)

add_executable(test_map test_map.cpp)
SET_PROPERTY(TARGET test_map PROPERTY CXX_STANDARD 11)

