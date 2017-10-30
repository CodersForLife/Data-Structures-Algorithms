
import java.util.Scanner;

public class BinarySearch {

	public static int binarySearch(int arr[], int num, int startIndex,
			int endIndex) {
		if (startIndex > endIndex) {
			return -1;
		}
		int mid = startIndex + (endIndex - startIndex) / 2;
		if (num == arr[mid]) {
			return mid;
		} else if (num > arr[mid]) {
			return binarySearch(arr, num, mid + 1, endIndex);
		} else {
			return binarySearch(arr, num, startIndex, mid - 1);
		}
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int size = s.nextInt();
		int[] arr = new int[size];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = s.nextInt();
		}
		int num = s.nextInt();
		int position = binarySearch(arr, num, 0, size - 1);
		if (position == -1) {
			System.out.println("The number is not present in the array");
		} else {
			System.out.println("The position of number in array is : "
					+ position);
		}
		s.close();
	}

}
