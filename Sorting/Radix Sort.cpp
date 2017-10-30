#include<bits/stdc++.h>

using namespace std;

void radixSort(int *arr, int &no_of_elmnts){
	int min = INT_MAX;
	int max = INT_MIN;

	for(int i=0;i<no_of_elmnts;i++){
		if(arr[i]>max){
			max = arr[i];
			continue;
		}
		if(arr[i]<min){
			min=arr[i];
		}
	}

	if(min<0){
		for(int i=0;i<no_of_elmnts;i++){
			arr[i]+=abs(min);
		}
		max+=abs(min);
	}

	int rounds=0;
	while(max){
		rounds++;
		max/=10;
	}

	vector< list<int> > buckets;
	int place_value=1;
	for(int i=0;i<rounds;i++){
		buckets.clear();
		buckets.resize(10);
		
		for(int j=0;j<no_of_elmnts;j++){
			buckets[ (arr[j]/place_value) % 10 ].push_back(arr[j]);
		}

		int arr_index=0;
		for(int j=0;j<10;j++){
			list<int>::iterator it;
			for(it=buckets[j].begin(); it!=buckets[j].end();it++){
				arr[arr_index++]=*it;
			}
		}
		place_value*=10;
	}

	if(min<0){
		for(int i=0;i<no_of_elmnts;i++){
			arr[i]+=min;
		}
	}
}
int main(){
	// freopen("input.txt", "rd", stdin);
	
	int no_of_elmnts;
	cin>>no_of_elmnts;

	int *arr = new int[no_of_elmnts];

	for(int i=0;i<no_of_elmnts;i++){
		cin>>arr[i];
	}
	radixSort(arr, no_of_elmnts);

	return 0;
}