// A fairly verbose implementation of selection sort

#include <iostream>
#include <algorithm>
#include <functional>

inline bool ascending(int x, int y)
{
	return x > y;
}

inline bool descending(int x, int y)
{
	return x < y;
}

void selection_sort(int *array, std::size_t size, std::function<bool(int, int)> direction) 
{
	for (std::size_t current_index = 0; current_index < size; ++current_index)
	{
		// The element we want to swap
		int preferred_index = current_index;

		for (std::size_t next_index = current_index + 1; next_index < size; ++next_index)
		{
			if (direction(array[preferred_index], array[next_index]))
				preferred_index = next_index;
		}
		
		std::swap(array[current_index], array[preferred_index]);
		
	}
}

int main()
{

	const std::size_t size = 5;
	int array[size] = { 8, 5, 4, 2, 1 };
	selection_sort(array, size, ascending);
	
	for (std::size_t i = 0; i < size; ++i)
		std::cout << array[i] << '\n';

    return 0;
}

