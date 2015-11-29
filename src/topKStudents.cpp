/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};
void sort(struct student *students, int first, int last){
	int i, j, pivot;
	struct student temp;
	if (students[first].score<students[last].score){
		pivot = first;
		i = first;
		j = last;

		while (i<j){
			while (students[i].score >= students[pivot].score && i<last)
				i++;
			while (students[j].score<students[pivot].score)
				j--;
			if (i<j){
				temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}

		temp = students[pivot];
		students[pivot] = students[j];
		students[j] = temp;
		sort(students, first, j - 1);
		sort(students, j + 1, last);

	}
}
struct student ** topKStudents(struct student *students, int len, int K) {
	struct student **result=NULL;
	int i;
	if (students == NULL || len < 0 || K < 0 || K > len)
		return NULL;
	sort(students, 0, len - 1);
	(*result) = (struct student *) malloc(sizeof(struct student)*K);
	if (K == 1)
	{
		result[0] = (struct student *)malloc(sizeof(struct student));
		result[0]->name = students[len - 1].name;
		result[0]->score = students[len - 1].score;
	}
	else
	{
		result = (struct student **)malloc(sizeof(struct student)*K);
		for (i = len - K,K=K-1; i < len; i++,K--)
		{
			result[K] = (struct student *)malloc(sizeof(struct student));
			result[K]->name = students[i].name;
			result[K]->score = students[i].score;
		}
	}
	return result;
}