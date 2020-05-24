#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Graph.h"

using namespace std;

Graph* LoadGraph(const char *FilePath)
{
    ifstream File(FilePath);

    if(!File)
    {
        cout << "Could not open file" << endl;
        return nullptr;
    }

    int NumberOfClauses, Source, Destination, SourceBar, DestinationBar;

    File >> NumberOfClauses;

    Graph *SATGraph = new Graph(2 * NumberOfClauses + 1);

    for(int CurrentClaus = 0; CurrentClaus < NumberOfClauses; CurrentClaus++)
    {
        File >> Source;
        File >> Destination;

        SourceBar = NumberOfClauses + Source;
        DestinationBar = NumberOfClauses + Destination;

        if(Source < 0)
        {
            SourceBar = -Source;
            Source = NumberOfClauses - Source;
        }

        if(Destination < 0)
        {
            DestinationBar = - Destination;
            Destination = NumberOfClauses - Destination;
        }

        SATGraph->AddEdge(SourceBar, Destination);
        SATGraph->AddEdge(DestinationBar, Source);
    }

    return SATGraph;
}

bool ComputeSatisfiability(const char *FileName)
{
    Graph *SATGraph = LoadGraph(FileName);

    if(SATGraph == nullptr)
    {
        exit(4);
    }
    //SATGraph->PrintGraph();

    vector<int> StronglyConnectedComponents = SATGraph->ComputeStronglyConnectedComponents();
    int NumberOfClauses = (SATGraph->GetNumberOfVertices() - 1) / 2;
    for(int CurrentClaus = 1; CurrentClaus <= NumberOfClauses; CurrentClaus++)
    {
        //cout << StronglyConnectedComponents[CurrentClaus] << "  " << StronglyConnectedComponents[NumberOfClauses + CurrentClaus] << endl;

        if(StronglyConnectedComponents[CurrentClaus] == StronglyConnectedComponents[NumberOfClauses + CurrentClaus])
        {
            //cout << CurrentClaus << endl;
            return false;
        }

    }

    return true;
}

int main()
{
    string Result;
    const char*  FILE_PATH[]= {"../2sat1.txt", "../2sat2.txt", "../2sat3.txt",
                               "../2sat4.txt", "../2sat5.txt", "../2sat6.txt"};

    for(auto FilePath: FILE_PATH)
    {
        if(ComputeSatisfiability(FilePath))
        {
            Result.push_back('1');
        }
        else
        {
            Result.push_back('0');
        }
    }

    cout << Result << endl;

    return 0;
}
