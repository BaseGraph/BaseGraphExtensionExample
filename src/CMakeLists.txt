add_library(example functions.cpp)

set_target_properties(example PROPERTIES
    LINKER_LANGUAGE CXX
    POSITION_INDEPENDENT_CODE TRUE # Required flag to generate Python bindings
)
target_include_directories(example PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>" # Required for cmake install
)
target_link_libraries(example BaseGraph::core)

# Place extension target to export at cmake install
list(APPEND EXPORTED_TARGETS example)
# Update targets to project's CMakeLists.txt
set(EXPORTED_TARGETS ${EXPORTED_TARGETS} PARENT_SCOPE)
