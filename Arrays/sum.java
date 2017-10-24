import java.util.*;
import java.math.*;

public class sum {
    static void printMaxSum(int[] arr){

    //1) For max continuous sub array
    int max_ending_here = 0;
    int max_so_far = Integer.MIN_VALUE;
    /*OR int max_so_far = arr[0];*/

    for(int x : arr){
        max_ending_here = Math.max(x, max_ending_here + x);
        max_so_far = Math.max(max_so_far, max_ending_here);
    }

    System.out.print(max_so_far);

    //2) For max non-continuous sub array, order doesn't matter
    Arrays.sort(arr);
    int sum = 0;

    //if there is none positive value in entire array
    if(arr[arr.length-1] <= 0)
        sum = arr[arr.length - 1];
    //accumulate all positive values in entire array
    else{
        for(int x : arr){
            if(x > 0)
                sum += x;
        }
    }
    System.out.println(" " + sum);
    }
    
    public static void main(String args[] ) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int i=0; i<t ; i++) {
            int n = sc.nextInt();
            int [] arr = new int[n];
            for(int j=0; j<n; j++) {
                arr[j] = sc.nextInt();
            }
            printMaxSum(arr);
        }
    }
}
