//EUNIX-TRIX


#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
vector<int> selection_sort(vector<int>);
void swap(int&, int&);
int main()
{
	int i, j;
	
	int input;
	typedef vector<int>::iterator iter;
	
	vector<int> arr;
	cout << "Enter the array you want to sort and press 9999 to stop" << endl;
	while ((cin >> input) && input != 9999 )
	{
		arr.push_back(input);
	}
	vector<int> arr_sort = selection_sort(arr);
	for (iter i = arr_sort.begin(); i != arr_sort.end(); i++)
	{
		cout << *i << "\t";
	}
	return 0;
}

vector<int> selection_sort(vector<int> arr)
{
	int i ,j;
	for (i = 0; i != arr.size()-1; i++)
	{
		int min_index = i;
		int small = arr[i];
		for (j = i + 1; j != arr.size(); j++)
		{
			if (arr[j] < small)
			{
				
				small = arr[j];
				min_index = j;
				
			}
			
		}
		if (min_index != i)
		{
			swap(arr[i], arr[min_index]);
		}
	}
	return arr;
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}


