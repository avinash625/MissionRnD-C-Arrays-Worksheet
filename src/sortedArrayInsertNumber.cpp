/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr == NULL || len < 0)
		return NULL;
	Arr = (int *)realloc(Arr,sizeof(int)*len+1);
	if (Arr == NULL)
		return NULL;
	for (len = len - 1; len >= 0; len--)
	{
		 if (Arr[len]>num)
			Arr[len + 1] = Arr[len];
		else
		{
			Arr[len + 1] = num;
			return Arr;
		}
	}
	if (len == -1)
		Arr[len + 1] = num;
	return Arr;
}