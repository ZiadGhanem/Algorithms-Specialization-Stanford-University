#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"

struct Graph
{
    int NumberOfVertices;
    Vertex* Vertices;

    Graph(int NumberOfVertices);

    void AddEdge(int Source, int Destination);
    int GetNumberOfVertices(void);
    Graph* CreateReverseGraph(void);
    vector<int> GetTopologicalOrder(void);
    void DepthFirstSearch(int SourceVertex, vector<int> &TopologicalOrder);
    vector<int> ComputeStronglyConnectedComponents(void);
    void PrintGraph(void);
};


#endif //GRAPH_H
