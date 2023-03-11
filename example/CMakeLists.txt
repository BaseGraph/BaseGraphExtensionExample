cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(BaseGraphExampleLink LANGUAGES CXX)

# Set C++11 requirements
set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED on)

# Import BaseGraph package and the extension
find_package(BaseGraph REQUIRED)
find_package(BaseGraphExample REQUIRED)

# Create executable
add_executable(usage_example usage_example.cpp)
# Link executable to the extension
target_link_libraries(usage_example BaseGraph::example)
