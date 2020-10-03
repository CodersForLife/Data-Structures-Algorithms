#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int find_start_index(vector<int> vec, int target){
	int index=-1;
	int start=0;
	int end=vec.size()-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(vec[mid]>=target){
			end=mid-1;
		}
		else{
			start=mid+1;
		}
		if(vec[mid]==target){
			index=mid;
		}
	}
	return index;
}

int find_end_index(vector<int> vec, int target){
	int index=-1;
	int start=0;
	int end=vec.size()-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(vec[mid]<=target){
			start=mid+1;
		}
		else{
			end=mid-1;
		}
		if(vec[mid]==target){
			index=mid;
		}
	}
	return index;
}

int main(){

	int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	int target;
	cin>>target;
	int start=find_start_index(v,target);
   	int end=find_end_index(v,target);
  	cout<<start<<" "<<end<<endl;

	return 0;
}
