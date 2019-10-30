#include<algorithm>
using namespace std;

class BubbleSort
{
public:
	void bubbleSort(int* arr, int length)
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = i + 1; j < length; j++)
			{
				if (arr[i] > arr[j])
					swap(arr[i], arr[j]);
			}
		}
	}

	// Returns true in case of 
	bool different(int* source, int* target, int length)
	{
		for (int i = 0; i < length; i++)
			if (source[i] != target[i])
				return true;
		return false;
	}
	// Prints the content of an array
	void print(int* arr, int length)
	{
		for (int i = 0; i < length; i++)printf("%d ", arr[i]);
		printf("\n");
	}
};

int main()
{
	int fails = 0;

	// create 100 random arrays, sort with BubbleSort and algorithm.sort(), then compare
	for (int i = 0; i < 10; i++)
	{
		int len = rand() % 10000 + 1;
		int* source = new int[len];
		int* target = new int[len];
		for (int i = 0; i < len; i++)
			source[i] = target[i] = rand() % INT_MAX - RAND_MAX / 2;
		BubbleSort s;
		s.bubbleSort(source, len);
		sort(target, target + len);
		fails += s.different(source, target, len);

	}
	printf("%d <- This should always be 0.",fails);

	return 0;
}
