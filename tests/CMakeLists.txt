find_package(GTest REQUIRED)

add_executable(test_example test_example.cpp)
target_link_libraries(test_example example gtest gtest_main)
add_test(test_example test_example)
