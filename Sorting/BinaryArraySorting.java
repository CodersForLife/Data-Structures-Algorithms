// JAVA Code for Sort a binary 
// array using one traversal 
public class BinaryArraySorting {

	public static void main(String[] args) {
		
		int[] arr= {1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,0,0,0,1,1,0};
		
		binaryArraySorting(arr);
		
		for(int val:arr) {
			System.out.print(val+" ");
		}

	}

	private static void binaryArraySorting(int[] arr) {
			
		int j=-1;
		for(int i=0;i<arr.length;i++) {
			
			if(arr[i]<1) {
				j++;
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
			
		}
		
	}

}
