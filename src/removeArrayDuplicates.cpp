/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
void sortmarks(int *Arr, int first, int last){
	int i, j, pivot, temp;
	if (first<last){
		pivot = first;
		i = first;
		j = last;

		while (i<j){
			while (Arr[i] <= Arr[pivot] && i<last)
				i++;
			while (Arr[j]>Arr[pivot])
				j--;
			if (i<j){
				temp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = temp;
			}
		}

		temp = Arr[pivot];
		Arr[pivot] = Arr[j];
		Arr[j] = temp;
		sortmarks(Arr, first, j - 1);
		sortmarks(Arr, j + 1, last);

	}
}
void * removeArrayDuplicates(int *Arr, int len)
{
	int i, j;
	if (Arr == NULL || len < 0)
		return NULL;
	else
	{
		sortmarks(Arr, 0, len-1);
		for (i = 0, j = 0; i < len; i++)
		{
			if (Arr[i] != Arr[i + 1])
			{
				Arr[j] = Arr[i];
				j++;
			}
			else
				Arr[j] = Arr[i];
		}
	}
}