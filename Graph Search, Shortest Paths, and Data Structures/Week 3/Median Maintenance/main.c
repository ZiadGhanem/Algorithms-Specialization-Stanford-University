#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define NUM_ELEMENTS (unsigned int)10000

static int32_t HeapHighSize = 0, HeapLowSize = 0;

bool Read_File(int8_t *FileName, uint32_t *InputData)
{
    FILE* FilePtr = fopen(FileName, "r");
    unsigned int ElementIndex;
    if(FilePtr == NULL)
    {
        return false;
    }
    for(ElementIndex = 0; fscanf(FilePtr,"%d\n", &InputData[ElementIndex]) && ElementIndex < NUM_ELEMENTS; ElementIndex++);
    fclose(FilePtr);
    return true;
}

void HeapHigh_Insert(uint32_t* HeapHigh, uint32_t Key)
{
    uint32_t CurrentIndex, TemporaryVariable;
    HeapHigh[HeapHighSize] = Key;
    CurrentIndex = HeapHighSize;
    while(CurrentIndex && (HeapHigh[CurrentIndex / 2] > HeapHigh[CurrentIndex]))
    {
        TemporaryVariable = HeapHigh[CurrentIndex];
        HeapHigh[CurrentIndex] = HeapHigh[CurrentIndex / 2];
        HeapHigh[CurrentIndex / 2] = TemporaryVariable;
        CurrentIndex /= 2;
    }
    HeapHighSize ++;
}

void HeapHigh_ExtractMin(uint32_t* HeapHigh)
{
    uint32_t CurrentIndex = 0, SmallestChildIndex, TemporaryVariable;
    HeapHigh[CurrentIndex] = HeapHigh[HeapHighSize - 1];
    HeapHighSize--;
    while(((2 * CurrentIndex + 1) < HeapHighSize) && ((HeapHigh[CurrentIndex] > HeapHigh[2 * CurrentIndex + 1]) || (HeapHigh[CurrentIndex] > HeapHigh[2 * CurrentIndex + 2])))
    {
        SmallestChildIndex = (HeapHigh[2 * CurrentIndex + 1] < HeapHigh[2 * CurrentIndex + 2]) ? (2 * CurrentIndex + 1):(2 * CurrentIndex + 2);
        TemporaryVariable = HeapHigh[CurrentIndex];
        HeapHigh[CurrentIndex] = HeapHigh[SmallestChildIndex];
        HeapHigh[SmallestChildIndex] = TemporaryVariable;
        CurrentIndex = SmallestChildIndex;
    }
}

void HeapLow_Insert(uint32_t* HeapLow, uint32_t Key)
{
    uint32_t CurrentIndex, TemporaryVariable;
    HeapLow[HeapLowSize] = Key;
    CurrentIndex = HeapLowSize;
    while(CurrentIndex && (HeapLow[CurrentIndex / 2] < HeapLow[CurrentIndex]))
    {
        TemporaryVariable = HeapLow[CurrentIndex];
        HeapLow[CurrentIndex] = HeapLow[CurrentIndex / 2];
        HeapLow[CurrentIndex / 2] = TemporaryVariable;

        CurrentIndex /= 2;
    }
    HeapLowSize ++;
}

void HeapLow_ExtractMax(uint32_t* HeapLow)
{
    uint32_t CurrentIndex = 0, SmallestChildIndex, TemporaryVariable;
    HeapLow[CurrentIndex] = HeapLow[HeapLowSize - 1];
    HeapLowSize--;
    while(((2 * CurrentIndex + 1) < HeapLowSize) && ((HeapLow[CurrentIndex] < HeapLow[2 * CurrentIndex + 1]) || (HeapLow[CurrentIndex] < HeapLow[2 * CurrentIndex + 2])))
    {
        SmallestChildIndex = (HeapLow[2 * CurrentIndex + 1] > HeapLow[2 * CurrentIndex + 2]) ? (2 * CurrentIndex + 1):(2 * CurrentIndex + 2);
        TemporaryVariable = HeapLow[CurrentIndex];
        HeapLow[CurrentIndex] = HeapLow[SmallestChildIndex];
        HeapLow[SmallestChildIndex] = TemporaryVariable;
        CurrentIndex = SmallestChildIndex;
    }
}



int main()
{
    int8_t* FileName = "Median.txt";
    uint32_t InputData[NUM_ELEMENTS],
    HeapLow[NUM_ELEMENTS],
    HeapHigh[NUM_ELEMENTS],
    CurrentMedian = 0,
    ElementIndex;
    uint64_t SumOfMedians=0;
    if(Read_File(FileName, InputData))
    {
        for(ElementIndex=0; ElementIndex<NUM_ELEMENTS; ElementIndex++)
        {
            if(HeapLowSize == 0)
            {
                HeapLow_Insert(HeapLow, InputData[ElementIndex]);
            }
            else
            {
                if(InputData[ElementIndex] <= HeapLow[0])
                {
                    HeapLow_Insert(HeapLow, InputData[ElementIndex]);
                }
                else
                {
                    HeapHigh_Insert(HeapHigh, InputData[ElementIndex]);
                }
            }


            if(HeapHighSize - HeapLowSize > 1)
            {
                HeapLow_Insert(HeapLow, HeapHigh[0]);
                HeapHigh_ExtractMin(HeapHigh);
            }
            else if(HeapLowSize - HeapHighSize > 1)
            {
                HeapHigh_Insert(HeapHigh, HeapLow[0]);
                HeapLow_ExtractMax(HeapLow);
            }
            else
            {

            }


            if(HeapHighSize > HeapLowSize)
            {
                CurrentMedian = HeapHigh[0];
            }
            else
            {
                CurrentMedian = HeapLow[0];
            }

            SumOfMedians += CurrentMedian;
            printf("%d, ", CurrentMedian);
        }

        /*
        for(ElementIndex = 0; ElementIndex<HeapLowSize; ElementIndex++)
        {
            printf("(%d) %d, ", ElementIndex+1, HeapLow[ElementIndex]);
        }
        printf("\n");
        HeapLow_ExtractMax(HeapLow);
        for(ElementIndex = 0; ElementIndex<HeapLowSize; ElementIndex++)
        {
            printf("(%d) %d, ", ElementIndex+1, HeapLow[ElementIndex]);
        }
        */
        /*
        for(ElementIndex = 0; ElementIndex<HeapHighSize; ElementIndex++)
        {
            printf("%d, ", HeapHigh[ElementIndex]);
        }
        printf("\n**************************************************************************************\n");
        for(ElementIndex = 0; ElementIndex<HeapLowSize; ElementIndex++)
        {
            printf("%d, ", HeapLow[ElementIndex]);
        }
        */
        printf("\n\nResult = %d", SumOfMedians);
    }
    else
    {
        printf("Could not open file %s", FileName);
    }
    return 0;
}

