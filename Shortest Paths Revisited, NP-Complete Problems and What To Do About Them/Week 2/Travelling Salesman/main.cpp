#include <iostream>
#include <algorithm>
#include <cfloat>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

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

    int NumberOfPoints;
    File >> NumberOfPoints;

    vector<Point> Points(NumberOfPoints);

    for(int PointIndex = 0; PointIndex < NumberOfPoints; PointIndex++)
    {
        File >> Points[PointIndex].x >> Points[PointIndex].y;
    }
    return Points;
}


vector<vector<float>> CalculateDistanceMatrix(vector<Point> &Points)
{
    vector<vector<float>> DistanceMatrix(Points.size(), vector<float>(Points.size()));
    for(int i = 0; i < Points.size(); i++)
    {
        for(int j = 0; j < Points.size(); j++)
        {
            DistanceMatrix[i][j] = (i == j)? 0: sqrt(pow(Points[i].x - Points[j].x, 2) + pow(Points[i].y - Points[j].y, 2));
        }
    }
    return DistanceMatrix;
}


float TravellingSalesman(vector<Point> &Points, vector<vector<float>> &DistanceMatrix)
{
    int NumberOfPoints = Points.size(),
    NumberOfSubsets = 1 << NumberOfPoints;

    vector<vector<float>> LookupTable(NumberOfSubsets, vector<float>(NumberOfPoints, FLT_MAX));

    LookupTable[1][0] = 0;

    for(int CurrentSize = 2; CurrentSize <= NumberOfPoints; CurrentSize++)
    {
        string StringMask(CurrentSize, 1);
        StringMask.resize(NumberOfPoints, 0);

        do
        {
            if(!StringMask[0])
            {
                continue;
            }

            int BitMask = 1;
            for(int CurrentPoint = 1; CurrentPoint < NumberOfPoints; CurrentPoint++)
            {
                if(StringMask[CurrentPoint])
                {
                    BitMask |= 1 << CurrentPoint;
                }
            }

            for(int j = 1; j < NumberOfPoints; j++)
            {
                if((BitMask >> j) & 1)
                {
                    int ReverseBitMask = BitMask ^ (1 << j);
                    float MinimumCost = FLT_MAX;
                    for(int k = 0; k < NumberOfPoints; k++)
                    {
                        if((ReverseBitMask >> k) & 1)
                        {
                            MinimumCost = min(LookupTable[ReverseBitMask][k] + DistanceMatrix[k][j], MinimumCost);
                        }
                    }
                    LookupTable[BitMask][j] = MinimumCost;
                }
            }
        }
        while(prev_permutation(begin(StringMask), end(StringMask)));
    }

    float MinimumCost = FLT_MAX;
    for(int j = 2; j < NumberOfPoints; j++)
    {
        MinimumCost = min(LookupTable[NumberOfSubsets - 1][j] + DistanceMatrix[j][0], MinimumCost);
    }

    return MinimumCost;
}


int main(void)
{
    char *FILE_PATH = "tsp.txt";
    vector<Point> Points = LoadPoints(FILE_PATH);
    for(auto Point: Points)
    {
        cout << "X= " << Point.x << " , Y= " << Point.y << endl;
    }
    vector<vector<float>> DistanceMatrix = CalculateDistanceMatrix(Points);
    float MinimumCost = TravellingSalesman(Points, DistanceMatrix);
    printf("Minimum cost = %i\n", (int)floorf(MinimumCost));
}
