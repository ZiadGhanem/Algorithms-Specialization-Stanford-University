
def count_split_inversions(sorted_list_A, sorted_list_B):
        i = j = number_inversions = 0
        total_sorted_list = []
        while i < len(sorted_list_A) and j < len(sorted_list_B):
            if sorted_list_A[i] > sorted_list_B[j]:
                total_sorted_list.append(sorted_list_B[j])
                j += 1
                number_inversions += len(sorted_list_A) - i
            else:
                total_sorted_list.append(sorted_list_A[i])
                i += 1
        total_sorted_list += sorted_list_A[i:]
        total_sorted_list += sorted_list_B[j:]

        return total_sorted_list, number_inversions


def count_inversions(numbers_list):
    if len(numbers_list) <= 1:
        return numbers_list, 0
    else:
        n = len(numbers_list) // 2
        sorted_list_A, number_inversions_A = count_inversions(numbers_list[:n])
        sorted_list_B, number_inversions_B = count_inversions(numbers_list[n:])
        total_sorted_list, number_inversions_C = count_split_inversions(sorted_list_A, sorted_list_B)
        return total_sorted_list, number_inversions_A + number_inversions_B + number_inversions_C



def main():
    with open('IntegerArray.txt') as f:
        numbers_list = [int(number) for number in f.readlines()]

    _, number_inversions = count_inversions(numbers_list)
    print(numbers_list)
    print(number_inversions)



if __name__ == "__main__":
    main()