#include <stdio.h>
#include "quicksort.h"

int *quicksort(int numbers[], int size)
{
	if(size == 0 || size == 1)
	{
		return numbers;
	}
	
	else
	{
		int pivot = rand() % size;

		int smaller_than_pivot_tmp[size];
		int smaller_than_pivot_size = 0;
		int greater_than_pivot_tmp[size];
		int greater_than_pivot_size = 0;

		for(int i = 0; i < size; i++)
		{
			if(i != pivot)
			{
				if(numbers[i] <= numbers[pivot])
				{
					smaller_than_pivot_tmp[smaller_than_pivot_size++] = numbers[i];
				}
				
				else
				{
					greater_than_pivot_tmp[greater_than_pivot_size++] = numbers[i];
				}
			}
		}

		int smaller_than_pivot[smaller_than_pivot_size];
	       	arraycopy(smaller_than_pivot_tmp, smaller_than_pivot, 0, smaller_than_pivot_size);
		int greater_than_pivot[greater_than_pivot_size];
	       	arraycopy(greater_than_pivot_tmp, greater_than_pivot, 0, greater_than_pivot_size);

		int *smaller_sorted = quicksort(smaller_than_pivot, smaller_than_pivot_size);
		int *greater_sorted = quicksort(greater_than_pivot, greater_than_pivot_size);
		
		int *sorted_numbers = malloc(size * sizeof(int));
		
		arraycopy(smaller_sorted, sorted_numbers, 0, smaller_than_pivot_size);
		sorted_numbers[smaller_than_pivot_size] = numbers[pivot];
		arraycopy(greater_sorted, sorted_numbers, smaller_than_pivot_size + 1, greater_than_pivot_size);

		return sorted_numbers;
	}
}

void
arraycopy(int* origin, int* destination, int offset, int size)
{
	for(int i = offset, j = 0; j < size; i++, j++)
	{
		destination[i] = origin[j];
	}
}

