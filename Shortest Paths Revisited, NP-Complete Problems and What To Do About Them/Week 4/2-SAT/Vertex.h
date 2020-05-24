#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

using namespace std;

struct Vertex
{
    bool IsVisited;
    vector<int> Edges;

    Vertex();
};


#endif //VERTEX_H
