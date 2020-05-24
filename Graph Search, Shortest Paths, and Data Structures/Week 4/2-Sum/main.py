def binarySearch(arr, start, end, x):
    #Check base case
    if end >= start:
        mid = start + (end - start) // 2
        #If element is present in middle itself
        if arr[mid] == x:
            return mid
        # If element is smaller than mid, then it is in left subarray
        elif arr[mid] > x:
            return binarySearch(arr, start, mid-1, x)
        # Else the element can only be present in right subarray
        else:
            return binarySearch(arr, mid+1, end, x)
    else:
        # Element is not present in array
        return -1



def main():
    INTEGERS_FILE = "algo1-programming_prob-2sum.txt"
    integersList = list()
    with open(INTEGERS_FILE) as integersFile:
        for line in integersFile:
            integersList.append(int(line))

    # integarsList.sort()

    hashTable = dict()
    answers = {}

    for integer in integersList:
        hashTable[integer] = True
    """
    for integar in integarsList:
        for t in range(-10000, 10001):
            if binarySearch(integarsList, 0, len(integarsList) - 1, t - integar) != -1:
                numberTargets += 1
    """

    for integer in integersList:
        for target in range(-10000, 10001):
            if target - integer in hashTable:
                if integer == target - integer:
                    continue
                if target not in answers:
                    answers[target] = set([tuple(sorted([integer, target - integer]))])
                else:
                    answers[target].add(tuple(sorted([integer, target - integer])))

    print(len(answers))



if __name__ == "__main__":
    main()