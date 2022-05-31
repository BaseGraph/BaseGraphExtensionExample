#include "compiled_feature.h"


namespace BaseGraph { namespace Compiled {

void removeAnEdge(BaseGraph::UndirectedGraph& graph, BaseGraph::VertexIndex vertex1, BaseGraph::VertexIndex vertex2) {
     graph.removeEdgeIdx(vertex1, vertex2);
}

}} // BaseGraph::Compiled
