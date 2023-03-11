find_package(pybind11 REQUIRED)

pybind11_add_module(_example MODULE pybind.cpp)
target_link_libraries(_example PRIVATE example BaseGraph::core)

install(TARGETS _example DESTINATION ./basegraph/example)
install(FILES example/__init__.py DESTINATION ./basegraph/example)
