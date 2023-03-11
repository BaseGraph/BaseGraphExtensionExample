#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "BaseGraph/extensions/example/functions.h"

namespace py = pybind11;


PYBIND11_MODULE(_example, m) {
    py::module::import("basegraph"); // Required Python import to make the module usable
    m.def("create_house_graph", &BaseGraph::example::createHouseGraph);
}
