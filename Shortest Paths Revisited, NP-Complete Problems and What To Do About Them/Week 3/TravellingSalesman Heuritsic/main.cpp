#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <cfloat>
#include <algorithm>

using namespace std;

struct Point{
    float x;
    float y;

    Point(void) = default;
};


vector<Point> LoadPoints(char *FilePath)
{
    ifstream File(FilePath);
    if(!File)
    {
        fprintf(stderr, "Could not open file %s for reading\n", FilePath);
        return vector<Point>(0);
    }

    int NumberOfPoints, PointNumber;
    File >> NumberOfPoints;

    vector<Point> Points(NumberOfPoints);

    for(int PointIndex = 0; PointIndex < NumberOfPoints; PointIndex++)
    {
        File >> PointNumber >> Points[PointIndex].x >> Points[PointIndex].y;
    }
    return Points;
}


float TravellingSalesmanHeuristic(vector<Point> Points)
{
    int NumberOfPoints = Points.size(),
    MinimumPoint,
    LastVisited,
    TotalPointsVisited = 0;

    float TotalDistance = 0,
    MinimumDistance,
    CurrentDistance;

    vector<bool> Visited(NumberOfPoints, false);

    Visited[0] = true;
    LastVisited = 0;
    TotalPointsVisited++;

    while(TotalPointsVisited != NumberOfPoints)
    {
        MinimumDistance = FLT_MAX;
        for(int DestinationPoint = 0; DestinationPoint < NumberOfPoints; DestinationPoint++)
        {
            if(!Visited[DestinationPoint])
            {
                CurrentDistance = pow(Points[DestinationPoint].x - Points[LastVisited].x, 2) + pow(Points[DestinationPoint].y - Points[LastVisited].y, 2);
                if(CurrentDistance < MinimumDistance)
                {
                    MinimumDistance = CurrentDistance;
                    MinimumPoint = DestinationPoint;
                }
            }
        }
        Visited[MinimumPoint] = true;
        LastVisited = MinimumPoint;
        TotalDistance += sqrt(MinimumDistance);
        TotalPointsVisited++;
        cout << TotalDistance << endl;
    }
    TotalDistance += sqrt(pow(Points[0].x - Points[LastVisited].x, 2) + pow(Points[0].y - Points[LastVisited].y, 2));

    return TotalDistance;
}


int main()
{
    char *FILE_PATH = "../nn.txt";
    vector<Point> Points = LoadPoints(FILE_PATH);
    cout << int(TravellingSalesmanHeuristic(Points)) << endl;
}
