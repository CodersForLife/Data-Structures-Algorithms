public class MergeSort {
    
    public static void mergeSort(int[] arr) {
        mergeSort(arr, 0, arr.length-1);
    }

    public static void mergeSort(int[] arr, int leftIndex, int rightIndex) {
        int arrLen = rightIndex + 1 - leftIndex;

        if (arrLen > 1) {
            int midIndex = (leftIndex + rightIndex) / 2;

            mergeSort(arr, leftIndex, midIndex);
            mergeSort(arr, midIndex+1, rightIndex);
            merge(arr, leftIndex, midIndex, rightIndex);
        }
    }

    public static void merge(int[] arr, int leftIndex, int midIndex, int rightIndex) {
        int leftLen = midIndex + 1 - leftIndex;
        int rightLen = rightIndex - midIndex;

        int[] leftArr = new int[leftLen];
        int[] rightArr = new int[rightLen];

        for (int i = 0; i < leftLen; i++) {
            leftArr[i] = arr[i+leftIndex];
        }

        for (int j = 0; j < rightLen; j++) {
            rightArr[j] = arr[j+midIndex+1];
        }

        int i = 0;
        int j = 0;
        int k = leftIndex;

        while (i < leftLen && j < rightLen) {
            if (leftArr[i] < rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < leftLen) {
            arr[k] = leftArr[i];
            i++;
            k++;            
        }

        while (j < rightLen) {
            arr[k] = rightArr[j];
            j++;
            k++;            
        }
    }
}