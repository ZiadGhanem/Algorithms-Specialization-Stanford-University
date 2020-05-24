import random

# def quicksort_(array, left_index, right_index):
#     if left_index < right_index:
#         pivot_index = partition(array, left_index, right_index)
#
#         quicksort(array, left_index, pivot_index - 1)
#         quicksort(array, pivot_index + 1, right_index)
#
#     print(array)
#     return array
#
#
# def partition_(array, left_index, right_index):
#     # Choose pivot
#     pivot_index = left_index
#     pivot = array[left_index]
#     i = left_index + 1
#
#     # Swap element at pivot index and first element to set pivot as first element
#     array[pivot_index], array[left_index] = array[left_index], array[pivot_index]
#
#     for j in range(left_index + 1, right_index + 1):
#         if array[j] < pivot:
#             array[j], array[i] = array[i], array[j]
#             i += 1
#
#     array[left_index], array[i - 1] = array[i - 1], array[left_index]
#
#     return i-1
#

def quicksort(unsorted_array):
    if len(unsorted_array) <= 1:
        return unsorted_array
    else:
        global total_comparisons
        total_comparisons += len(unsorted_array) - 1

        # Choose a pivot randomly
        pivot_index = random.randint(0, len(unsorted_array) - 1)
        pivot = unsorted_array[pivot_index]
        i = 1

        # Swap element at pivot index and first element to set pivot as first element
        unsorted_array[pivot_index], unsorted_array[0] = unsorted_array[0], unsorted_array[pivot_index]

        for j in range(1, len(unsorted_array)):
            if unsorted_array[j] < pivot:
                unsorted_array[j], unsorted_array[i] = unsorted_array[i], unsorted_array[j]
                i += 1

        unsorted_array[0], unsorted_array[i - 1] = unsorted_array[i - 1], unsorted_array[0]

        pivot_index = i - 1

        sorted_array_left = quicksort(unsorted_array[:pivot_index])
        sorted_array_right = quicksort(unsorted_array[pivot_index + 1:])

        sorted_array = sorted_array_left + [unsorted_array[pivot_index]] + sorted_array_right

        return sorted_array


if __name__ == "__main__":
    total_comparisons = 0
    with open('QuickSort.txt') as f:
        unsorted_array = [int(number) for number in f.readlines()]
    print("Unsorted Array= ")
    print(unsorted_array)
    sorted_array = quicksort(unsorted_array)
    print("\nSorted Array=")
    print(sorted_array)
    print("\nTotal Comparisons=")
    print(total_comparisons)