# BaseGraph - Extension example

[![C++ build](https://github.com/BaseGraph/BaseGraphExtensionExample/actions/workflows/build_cpp.yml/badge.svg)](https://github.com/BaseGraph/BaseGraphExtensionExample/actions/workflows/build_cpp.yml)
[![Python build](https://github.com/BaseGraph/BaseGraphExtensionExample/actions/workflows/python_build.yml/badge.svg)](https://github.com/BaseGraph/BaseGraphExtensionExample/actions/workflows/python_build.yml)

This project implements our suggested way to setup a [BaseGraph] extension. It
complements the
[documentation](https://base-graph.readthedocs.io/en/latest/extensions.html).

## Installation

Clone this repository
```
git clone https://github.com/BaseGraph/BaseGraphExample.git
```

### C++ library

After installing BaseGraph C++ as explained in the
[documentation](https://base-graph.readthedocs.io/en/latest/installation.html),
install this example library with the same commands:
```
cd BaseGraphExtensionExample
cmake -B build
cmake --build build
cmake --install build
```
The argument `prefix=/some/path` can be used to install the library in a custom
location (as opposed to onto the system), but this path must be set in the
`PATH` environment variable or must be provided to CMake with
```
cmake -DCMAKE_PREFIX_PATH="/some/path" -B build
```
to allow CMake to find the package from another project.

In a different project, use
```
find_package(BaseGraph)
find_package(BaseGraphExample)
...
target_link_libraries(<TARGET> BaseGraph::example)
```
in the `CMakeLists.txt` to use the functions defined in this library. An example is provided in the [example directory](example/README.md).

### Python module

While installing BaseGraph's Python module doesn't require installing the C++
library, installing BaseGraph extensions does. See the
[documentation](https://base-graph.readthedocs.io/en/latest/installation.html)
for instructions. Installing this extension also requires installing
BaseGraph's Python module. However, this extension's C++ library doesn't
need to be installed nor compiled.

To install the Python module, install the dependencies
```
pip install -r requirements.txt
```
and then the module
```
pip install .
```
This `example` module is automatically recognized by BaseGraph's Python module, meaning that it can be imported from `basegraph`
```python
import basegraph
# or from basegraph import example

graph = basegraph.example.create_house_graph()
```

[BaseGraph]: https://github.com/BaseGraph/BaseGraph
