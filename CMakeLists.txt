
cmake_minimum_required(VERSION 3.5)

project (boost_pointer CXX)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
endif()

find_package (Boost 1.58.0 COMPONENTS system thread filesystem program_options)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})

add_executable(boost_pointer boost_test.cpp)
SET_PROPERTY(TARGET boost_pointer PROPERTY CXX_STANDARD 11)
add_executable(asio_test asio_test.cpp)
add_executable(boost_uuid boost_uuid.cpp)
target_link_libraries(boost_pointer ${Boost_LIBRARIES})
target_link_libraries(asio_test ${Boost_LIBRARIES})
target_link_libraries(boost_uuid ${Boost_LIBRARIES})

#add_executable(test_bind test_bind.cpp)
#SET_PROPERTY(TARGET test_bind PROPERTY CXX_STANDARD 11)
#target_link_libraries(test_bind dl pthread)

#add_executable(test_iterator test_iterator.cpp)
#SET_PROPERTY(TARGET test_iterator PROPERTY CXX_STANDARD 11)

add_executable(test_map test_map.cpp)
SET_PROPERTY(TARGET test_map PROPERTY CXX_STANDARD 11)

add_executable(test_clock test_clock.cpp)
SET_PROPERTY(TARGET test_clock PROPERTY CXX_STANDARD 11)

add_executable(test_time test_time.cpp)
SET_PROPERTY(TARGET test_clock PROPERTY CXX_STANDARD 11)

add_executable(test_replace test_replace.cpp)
SET_PROPERTY(TARGET test_clock PROPERTY CXX_STANDARD 11)

add_subdirectory(Decorator)
add_subdirectory(Bridge)
#add_subdirectory(Transaction)

add_executable(remove_duplicate leecode26.cpp)
SET_PROPERTY(TARGET remove_duplicate PROPERTY CXX_STANDARD 11)

add_executable(remove_duplicate2 leecode80.cpp)
SET_PROPERTY(TARGET remove_duplicate2 PROPERTY CXX_STANDARD 11)

add_executable(minSubArrayLen leetcode209.cpp)
SET_PROPERTY(TARGET minSubArrayLen PROPERTY CXX_STANDARD 11)

add_executable(lengthOfLongestSubstring leetcode3.cpp)
SET_PROPERTY(TARGET lengthOfLongestSubstring PROPERTY CXX_STANDARD 11)

add_executable(ValidAnagram leetcode242.cpp)
SET_PROPERTY(TARGET ValidAnagram PROPERTY CXX_STANDARD 11)

add_executable(HappyNumber leetcode202.cpp)
SET_PROPERTY(TARGET HappyNumber PROPERTY CXX_STANDARD 11)

add_executable(WordPattern leetcode290.cpp)
SET_PROPERTY(TARGET WordPattern PROPERTY CXX_STANDARD 11)

add_executable(IsomorphicStrings leetcode205.cpp)
SET_PROPERTY(TARGET IsomorphicStrings PROPERTY CXX_STANDARD 11)

add_executable(TwoSums leetcode1.cpp)
SET_PROPERTY(TARGET TwoSums PROPERTY CXX_STANDARD 11)

add_executable(ThreeSum leetcode15.cpp)
SET_PROPERTY(TARGET ThreeSum PROPERTY CXX_STANDARD 11)

add_executable(FourSum leetcode454.cpp)
SET_PROPERTY(TARGET FourSum PROPERTY CXX_STANDARD 11)

add_executable(template_test template_test.cpp)
SET_PROPERTY(TARGET template_test PROPERTY CXX_STANDARD 11)