public class QuickSort {

    public static void quickSort(int[] arr) {
        quickSort(arr, 0, arr.length-1);
    }

    public static void quickSort(int[] arr, int leftIndex, int rightIndex) {
        int arrLength = rightIndex + 1 - leftIndex;

        if (arrLength > 1) {
            int partitionIndex = partition(arr, leftIndex, rightIndex);

            quickSort(arr, leftIndex, partitionIndex-1);
            quickSort(arr, partitionIndex+1, rightIndex);
        }
    }

    public static int partition(int[] arr, int leftIndex, int rightIndex) {
        int pivot = arr[rightIndex];
        int partitionIndex = leftIndex;

        for (int i = leftIndex; i < rightIndex; i++) {
            if (arr[i] < pivot) {
                swap(arr, i, partitionIndex);
                partitionIndex++;
            }
        }
        swap(arr, partitionIndex, rightIndex);

        return partitionIndex;
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}