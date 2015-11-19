/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void swap(int *Arr, int a, int b)
{
	int temp;
	temp = Arr[a];
	Arr[a] = Arr[b];
	Arr[b] = temp;
}

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i, m1, flag = 0, redundant = 0;
	if (Arr == NULL || len < 0)
		return NULL;
	if (len == 2)
	{
		printf("assuming that the array is in sorted(ascending order)\n");
		if (Arr[0]>Arr[1])
		{
			swap(Arr, 0, 1);
		}
	}
	else if (len>2)
	{
		for (i = 1; i<len; i++)
		{
			if (Arr[0]>Arr[1] && i == 1)
			{
				m1 = 0;
				flag = 1;
				if (len == 3){
					if (Arr[i + 1]<Arr[m1] && len == 3)
						swap(Arr, m1, i + 1);
					else if (Arr[i]<Arr[m1])//condition if the 2 elements are at the first 2 positions itself
						swap(Arr, m1, i);
				}
				else if (Arr[m1]<Arr[i + 1])        //condition to check if the 2 misplaced elements are in the first 2 positions
					swap(Arr, m1, i);
				else if (Arr[m1]>Arr[i + 1] && Arr[m1]<Arr[i + 2])
					swap(Arr, m1, i + 1);
			}
			else if (Arr[i] == Arr[i + 1] && redundant == 0 && flag != 1)
			{
				if (i == 1 && Arr[i - 1] == Arr[i])//condition to check if the element is in the first position and along with redundant elements
					m1 = i - 1;
				else
					m1 = i;
				redundant = 1;
			}
			else if (Arr[i]<Arr[i + 1] && redundant == 1 && flag != 1)
			{
				m1 = i;
				redundant = 0;//removing the redundant flag if the next number is not equal.
			}
			else if (Arr[i]>Arr[i + 1] && flag == 0)//condition to capture the first conflict(misplaced element )
			{

				flag = 1;
				if (redundant != 1)
					m1 = i;
				if (i == len - 2)
					swap(Arr, m1, i + 1);
				else if (Arr[i]>Arr[i + 1])
				if (Arr[i + 1]<Arr[i + 2])
					swap(Arr, m1, i + 1);

			}
			else if (flag == 1)//finding the second conflict 
			{
				if (i == len - 1)
				{
					if (Arr[m1]>Arr[i])
					{
						swap(Arr, m1, i);
					}
				}
				else if (Arr[i]>Arr[i + 1])
					swap(Arr, m1, i + 1);
			}
		}

	}
}
