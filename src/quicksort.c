#include <stdio.h>
#include "quicksort.h"

int *quicksort(int *numbers, int size)
{
	if(size == 0)
	{
		int empty[] = {};
		return empty;
	}
	
	else if(size == 1)
	{
		return numbers;
	}
	
	else
	{
		int pivot = rand() % size;

		int smaller_than_pivot_tmp[size];
		int smaller_than_pivot_length = 0;
		int greater_than_pivot_tmp[size];
		int greater_than_pivot_length = 0;
		
		for(int i = 0; i < size; i++)
		{
			if(i == pivot)
			{
				continue;
			}
			
			if(numbers[i] <= numbers[pivot])
			{
				smaller_than_pivot_tmp[smaller_than_pivot_length++] = numbers[i];
			}
			
			else
			{
				greater_than_pivot_tmp[greater_than_pivot_length++] = numbers[i];
			}
		}

		int smaller_than_pivot[smaller_than_pivot_length];
	       	arraycopy(smaller_than_pivot_tmp, smaller_than_pivot, 0, smaller_than_pivot_length);
		//free(smaller_than_pivot_tmp);

		int greater_than_pivot[greater_than_pivot_length];
	       	arraycopy(greater_than_pivot_tmp, greater_than_pivot, 0, greater_than_pivot_length);
		//free(greater_than_pivot_tmp);

		int *smaller_sorted = quicksort(smaller_than_pivot, smaller_than_pivot_length);
		int *greater_sorted = quicksort(greater_than_pivot, greater_than_pivot_length);

		int* sorted_numbers = malloc(size * sizeof(int));

		arraycopy(smaller_sorted, sorted_numbers, 0, smaller_than_pivot_length);
		//free(smaller_sorted);

		sorted_numbers[smaller_than_pivot_length] = numbers[pivot];

		arraycopy(greater_sorted, sorted_numbers, smaller_than_pivot_length + 1, greater_than_pivot_length);
		//free(greater_sorted);

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

