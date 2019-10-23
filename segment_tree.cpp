#include<bits/stdc++.h>
using namespace std;
//Sum of a given segment;
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
	//starting query is less than starting index of the seg and ending query is greater than 
	//ending index of the segment, then return the value store at that index;
	if(qs <= ss && qe >= se)
		return st[si];
	if(qs > se || qe < ss)
		return 0;
	int mid = (ss + se) / 2;
	return getSumUtil(st, ss, mid, qs, qe, 2*si+1) + getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
	if(i < ss || i > se)
		return;
	st[si] = st[si] + diff;
	if(ss != se)
	{
		int mid = (ss + se) / 2;
		//Break the segment tree into two parts and compute for each part to get updated segment tree;
		updateValueUtil(st, ss, mid, i, diff, 2*si+1);
		updateValueUtil(st, mid+1, se, i, diff, 2*si+2);
	}
}
//Update the value at a particular index in the array;
void updateValue(int arr[], int *st, int n, int i, int val)
{
	int diff = val - arr[i];
	arr[i] = val;
	updateValueUtil(st, 0, n-1, i, diff, 0);
}
//Calculate sum of a given segment in the array;
int getSum(int* st, int n, int qs, int qe)
{
	//If starting query is less than 0 or ending query is greater than length of the array
	//or starting query is greater than ending query the program will be terminated;
	if(qs < 0 || qe > n-1 || qe < qs)
		return -1;
	return getSumUtil(st, 0, n-1, qs, qe, 0);
}
//Computer power in log(n) time complexity;
int pown(int a, int b)
{
	if(b == 0)
		return 1;
	if(b == 1)
		return a;
	return pown(a, b/2) * pown(a, b - b/2);
}
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
	//if function goes to leaf node then data value will be value store in that segment in the given array;
	if(ss == se)
	{
		st[si] = arr[se];
		return arr[ss];
	}
	int mid = (ss + se) / 2;
	//Data value store in a node is the sum of data value store it's two child;
	st[si] = constructSTUtil(arr, ss, mid, st, 2*si+1) + constructSTUtil(arr, mid+1, se, st, 2*si+2);
	return st[si];
}
//Construct the segment tree;
int *constructST(int arr[], int n)
{
	int x = (int)(ceil(log2(n)));
	//Total no of leaf node in the segment tree;
	int max_size = 2 * pown(2, x) - 1;
	int *st = new int[max_size];
	//Construct the segment tree where data value store in a node is the sum of data value store it's two child;
	int val = constructSTUtil(arr, 0, n-1, st, 0);
	for(int i = 0; i < max_size; i++)
		cout << st[i] << " ";
	cout << endl;
	return st;
}
int main()
{
	int n;
	cin>>n;
	int arr[n+5];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	//Construct the Segment Tree;
	int *st = constructST(arr,n);
	//Get the sum of a given range;
	cout << getSum(st, n, 1, 3) << endl;
	//Update the value of a particular index in the given array;
	updateValue(arr, st, n, 1, 10);
	//Get the sum of a given range;
	cout << getSum(st, n, 1, 3) << endl;
	return 0;
}
