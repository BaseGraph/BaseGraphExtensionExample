#include "BaseGraph/extensions/example/functions.h"
#include <BaseGraph/undirectedgraph.h>


namespace BaseGraph { namespace example {

UndirectedGraph createHouseGraph() {
    UndirectedGraph graph(5);
    for (int i=0; i<5; i++)
        graph.addEdge(i, (i+1)%5);
    graph.addEdge(2, 4);
    return graph;
}

}} // BaseGraph::example
