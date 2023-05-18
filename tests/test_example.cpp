#include <list>

#include "gtest/gtest.h"
#include "BaseGraph/types.h"
#include "BaseGraph/extensions/example/functions.h"


using namespace std;


TEST(createHouseGraph, generatesHouseGraph){
    auto graph = BaseGraph::example::createHouseGraph();
    std::list<BaseGraph::Edge> expectedEdges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}, {2, 4}
    };

    for (auto edge: expectedEdges)
        EXPECT_TRUE(graph.hasEdge(edge.first, edge.second));
}
