#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

int * quicksort(int numbers[], int size)
{
	if(size == 0 || size == 1)
	{
		return numbers;
	}

	else
	{
		int pivot = rand() % size;

		int smaller_than_pivot[size];
		int smaller_than_pivot_size = 0;
		int greater_than_pivot[size];
		int greater_than_pivot_size = 0;

		for(int i = 0; i < size; i++)
		{
			if(i != pivot)
			{
				if(numbers[i] <= numbers[pivot])
				{
					smaller_than_pivot[smaller_than_pivot_size++] = numbers[i];
				}

				else
				{
					greater_than_pivot[greater_than_pivot_size++] = numbers[i];
				}
			}
		}

		int *smaller_sorted = quicksort(smaller_than_pivot, smaller_than_pivot_size);
		int *greater_sorted = quicksort(greater_than_pivot, greater_than_pivot_size);

		int *sorted_numbers = malloc(size * sizeof(int));
		arraycopy(smaller_sorted, sorted_numbers, 0, smaller_than_pivot_size);
		sorted_numbers[smaller_than_pivot_size] = numbers[pivot];
		arraycopy(greater_sorted, sorted_numbers, smaller_than_pivot_size + 1, greater_than_pivot_size);

		return sorted_numbers;
	}
}

void arraycopy(int *origin, int *destination, int offset, int size)
{
	for(int j = 0; j < size; j++)
	{
		destination[offset++] = origin[j];
	}
}

int main(int argc, char *argv[])
{
	int numbers_size = argc - 1;
	int numbers[numbers_size];

	for(int i = 0; i < numbers_size; i++)
	{
		numbers[i] = atoi(argv[i + 1]);
	}

	int *sorted_numbers = quicksort(numbers, numbers_size);

	print(sorted_numbers, numbers_size);

	return 0;
}

void print(int* array, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf(" %d ", array[i]);
	}

	printf("\n");
}
