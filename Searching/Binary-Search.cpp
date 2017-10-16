#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *arr,int low,int high,int x){
	if(high >= low){
		int mid = (low+high)/2;
		if(arr[mid] == x)	return mid;
		if(arr[mid] > x)	return binarySearch(arr,low,mid-1,x);
		if(arr[mid] < x)	return binarySearch(arr,mid+1,high,x);
	}
	return -1;
}

int main(){
	int n; // number of elemmets of array
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"\n Enter element to be searched\n";
	int x;
	cin>>x;
	int ret = binarySearch(a,0,n,x);
	(ret==-1) ? (cout<<"Element not present") : (cout<<"Element found at index "<<ret);
	return 0;
}