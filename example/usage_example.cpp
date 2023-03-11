#include <BaseGraph/extensions/example/functions.h>
#include <iostream>

int main() {
    auto graph = BaseGraph::example::createHouseGraph();
    std::cout << "The created house graph is\n" << graph << std::endl;
    return 0;
}
