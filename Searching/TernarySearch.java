/**
 * Program to demonstrate ternary search.
 */
public class TernarySearch {

    /**
     * searches given searchValue in an array.
     *
     * @param arr         Collection of data.
     * @param searchValue Value to be searched in given collection of data.
     * @param start       Start index; the searching will begin from this index in array.
     * @param end         End index; this the upper bound for search an element in array.
     * @return Index of element in array.
     */
    public static int ternarySearch(int[] arr, int searchValue, int start, int end) {
        if (start > end) {
            return -1;
        }
        int mid1 = start + (end - start) / 3;
        int mid2 = start + 2 * (end - start) / 3;

        if (arr[mid1] == searchValue) {
            return mid1;
        } else if (arr[mid2] == searchValue) {
            return mid2;
        } else if (searchValue < arr[mid1]) {
            return ternarySearch(arr, searchValue, start, mid1 - 1);
        } else if (searchValue > arr[mid2]) {
            return ternarySearch(arr, searchValue, mid2 + 1, end);
        } else {
            return ternarySearch(arr, searchValue, mid1, mid2);
        }
    }
}