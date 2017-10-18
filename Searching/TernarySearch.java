public class TernarySearch {

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

    public static void main(String[] args) {
        int[] numbers = {1, 2, 3};
        System.out.println("index - " + ternarySearch(numbers, 2, 0, 2));

    }
}