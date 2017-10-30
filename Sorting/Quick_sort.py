def quick_sort(arr, left_index, right_index):
    if left_index < right_index:
        partition_index = partition(arr, left_index, right_index)

        quick_sort(arr, left_index, partition_index-1)
        quick_sort(arr, partition_index+1, right_index)

def partition(arr, left_index, right_index):
    pivot = arr[right_index]
    partition_index = left_index

    for i in range(left_index, right_index):
        if arr[i] < pivot:
            arr[i], arr[partition_index] = arr[partition_index], arr[i]
            partition_index += 1
    arr[partition_index], arr[right_index] = arr[right_index], arr[partition_index]

    return partition_index

if __name__ == "__main__":
    arr = [1,3,5,4,2,6,8,9,7,10,13,12,14,16,15,17,19,18]

    quick_sort(arr, 0, len(arr)-1)
    print(arr)
