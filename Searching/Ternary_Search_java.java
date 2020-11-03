import java.util.*;
import java.io.*;

class Ternary_Search{
	public static void main(String args[]){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int arr[]=new int[n];
		for(int i=0;i<n;i++){
			arr[i]=s.nextInt();
		}
		int key=s.nextInt();
		int start=0;
		int end=n-1;
		Boolean flag=false;
		while(start<=end){
			int mid1=(start)+(end-start)/3;
			int mid2=start+(2*(end-start)/3);
			if(arr[mid1]==key){
				System.out.println("Value found at index "+mid1);
				flag=true;
				break;
			}
			if(arr[mid2]==key){
				System.out.println("Value found at index "+mid2);
				flag=true;
				break;
			}
			if(key<arr[mid1]){
				end=mid1-1;
			}
			else if(key>arr[mid1]){
				start=mid1+1;
			}
			else{
				start=mid1+1;
				end=mid2-1;
			}
		}
		if(flag==false){
			System.out.println("Value not  found in the array");
		}
	}
}
