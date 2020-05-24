#include <iostream>
#include <stack>
#include <algorithm>
#include <iostream>
#include "Graph.h"

Graph::Graph(int NumberOfVertices)
:NumberOfVertices(NumberOfVertices)
{
    this->Vertices = new Vertex[NumberOfVertices];
}


void Graph::AddEdge(int Source, int Destination)
{
    this->Vertices[Source].Edges.push_back(Destination);
}

int Graph::GetNumberOfVertices(void)
{
    return this->NumberOfVertices;
}

Graph* Graph::CreateReverseGraph(void)
{
    Graph *ReverseGraph = new Graph(this->NumberOfVertices);

    for(int SourceVertex = 0; SourceVertex < this->NumberOfVertices; SourceVertex++)
    {
        for(int DestinationVertex = 0; DestinationVertex < this->Vertices[SourceVertex].Edges.size(); DestinationVertex++)
        {
            ReverseGraph->AddEdge(this->Vertices[SourceVertex].Edges[DestinationVertex], SourceVertex);
        }
    }

    return ReverseGraph;
}

vector<int> Graph::GetTopologicalOrder(void)
{
    // Mark all vertices as unvisited
    for(int CurrentVertex = 0; CurrentVertex < this->NumberOfVertices; CurrentVertex++)
    {
        this->Vertices[CurrentVertex].IsVisited = false;
    }

    vector<int> TopologicalOrder;
    TopologicalOrder.reserve(this->NumberOfVertices - 1);

    // Because vertex 0 is unused
    for(int CurrentVertex = this->NumberOfVertices - 1; CurrentVertex > 0; CurrentVertex --)
    {
        if(!this->Vertices[CurrentVertex].IsVisited)
        {
            this->DepthFirstSearch(CurrentVertex, TopologicalOrder);
        }
    }

    // Mark all vertices as unvisited
    for(int CurrentVertex = 0; CurrentVertex < this->NumberOfVertices; CurrentVertex++)
    {
        this->Vertices[CurrentVertex].IsVisited = false;
    }

    return TopologicalOrder;
}

void Graph::DepthFirstSearch(int SourceVertex, vector<int> &TopologicalOrder)
{
    stack<int> DepthFirstSearchStack;
    bool AllVerticesVisited;
    int TopVertex;

    this->Vertices[SourceVertex].IsVisited = true;
    DepthFirstSearchStack.push(SourceVertex);

    while(!DepthFirstSearchStack.empty())
    {
        TopVertex = DepthFirstSearchStack.top();
        AllVerticesVisited = true;

        for (int &DestinationVertex: this->Vertices[TopVertex].Edges)
        {
            if (!this->Vertices[DestinationVertex].IsVisited)
            {
                AllVerticesVisited = false;
                this->Vertices[DestinationVertex].IsVisited = true;
                DepthFirstSearchStack.push(DestinationVertex);
                break;
            }
        }

        if (AllVerticesVisited)
        {
            TopologicalOrder.push_back(DepthFirstSearchStack.top());
            DepthFirstSearchStack.pop();
        }
    }
}


vector<int> Graph::ComputeStronglyConnectedComponents(void)
{
    Graph *ReverseGraph = this->CreateReverseGraph();
    vector<int> TopologicalOrder = ReverseGraph->GetTopologicalOrder();

    vector<int> StronglyConnectedComponents(this->NumberOfVertices);

    for_each(TopologicalOrder.rbegin(), TopologicalOrder.rend(), [&](int &CurrentVertex){
        if(!this->Vertices[CurrentVertex].IsVisited)
        {
            vector<int> Temporary;
            this->DepthFirstSearch(CurrentVertex, Temporary);

            for(int &Vertex: Temporary)
            {
                StronglyConnectedComponents[Vertex] = CurrentVertex;
            }
        }
    });

    return StronglyConnectedComponents;
}

void Graph::PrintGraph(void)
{
    for(int CurrentVertex = 0; CurrentVertex < this->NumberOfVertices; CurrentVertex++)
    {
        cout << CurrentVertex << "\t";
        for(int DestinationVertex = 0; DestinationVertex < this->Vertices[CurrentVertex].Edges.size(); DestinationVertex++)
        {
            cout << this->Vertices[CurrentVertex].Edges[DestinationVertex] << " ";
        }
        cout << endl;
    }
}
