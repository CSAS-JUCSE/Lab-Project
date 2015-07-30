#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill_int(int *array, int len)
{
	printf("Please enter %d integers each followed by a space.\n");
	int i;
	for(i = 0; i < len; i++) {
		scanf("%d", &array[i]);
	}
}
int linear_search_int(int *array, int len, int num)
{
	int i;
	for(i = 0; i < len; i++) {
		if(array[i] == num)
		return 1;
	}
	return 0;
}
void sort_int(int *array, int len)
{
	int i, j, temp;
	for(i = 1; i < len; i++)
	{
		temp = array[i];
		j = i - 1;
		while(j >= 0 && temp < array[j]){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}
}
int binary_search_int(int *array, int len, int num)
{
	int mid, low = 0, high = len - 1;
	while(low <= high){
		mid = (low + high) / 2;
		if(array[mid] == num)
			return 1;
		else if(array[mid] > num)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;	
}
void fill_float(float *array, int len)
{
	printf("Please enter %d floats each followed by a space.\n");
	int i;
	for(i = 0; i < len; i++) {
		scanf("%f", &array[i]);
	}
}
int linear_search_float(float *array, int len, float num)
{
	int i;
	for(i = 0; i < len; i++) {
		if(array[i] == num)
		return 1;
	}
	return 0;
}
void sort_float(float *array, int len)
{
	int i, j;
	float temp;
	for(i = 1; i < len; i++)
	{
		temp = array[i];
		j = i - 1;
		while(j >= 0 && temp < array[j]){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}
}
int binary_search_float(float *array, int len, float num)
{
	int mid, low = 0, high = len - 1;
	while(low <= high){
		mid = (low + high) / 2;
		if(array[mid] == num)
			return 1;
		else if(array[mid] > num)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;	
}
void fill_words(char **array, int len)
{
	printf("Please enter %d words each followed by a newline.\n");
	int i;
	for(i = 0; i < len; i++) {
		scanf("%s", array[i]);
	}
}
int linear_search_word(char **array, int len, char *word)
{
	int i;
	for(i = 0; i < len; i++) {
		if(strcmp(array[i], word) == 0)
		return 1;
	}
	return 0;
}
void sort_word(char **array, int len)
{
	int i, j;
	char temp[10];
	for(i = 1; i < len; i++)
	{
		strcpy(temp, array[i]);
		j = i - 1;
		while(j >= 0 && strcmp(array[j], temp) > 0){
			strcpy(array[j+1], array[j]);
			j--;
		}
		strcpy(array[j+1], temp);
	}
}
int binary_search_word(char **array, int len, char *word)
{
	int mid, low = 0, high = len - 1;
	while(low <= high){
		mid = (low + high) / 2;
		if(strcmp(array[mid], word) == 0)
			return 1;
		else if(strcmp(array[mid], word) > 0)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}
int main()
{
	int n, ch, choice, found;
	printf("Press 1 for integer.\n");
	printf("Press 2 for words.\n");
	printf("Press 3 for floats.\n");
	scanf("%d", &ch);
	switch(ch) {
		case 1:
			printf("Enter the length of array.\n");
			scanf("%d", &n);
			int *int_array;
			int_array = (int *)malloc(n * sizeof(int));
			fill_int(int_array, n);
			int num;
			printf("Enter the number you want to find?\n");
			scanf("%d", &num);
			printf("Press 1 for linear search.\n");
			printf("Press 2 for binary search.\n");
			scanf("%d", &choice);
			if(choice == 1) {
				found = linear_search_int(int_array, n, num);
			}
			else {
				sort_int(int_array, n);
				found = binary_search_int(int_array, n, num);
			}
			if(found)
				printf("%d FOUND in the array.\n", num);
			else
				printf("%d NOT FOUND in the array.\n", num);
			break;
		case 2:
			printf("Enter the length of array.\n");
			scanf("%d", &n);
			char **word_array;
			word_array = (char **)malloc(n * sizeof(char *));
			int i;
			for(i = 0; i < n; i++)
				word_array[i] = (char *)malloc(10 * sizeof(char));
			fill_words(word_array, n);
			char word[10];
			printf("Enter the word you want to find?\n");
			scanf("%s", word);
			printf("Press 1 for linear search.\n");
			printf("Press 2 for binary search.\n");
			scanf("%d", &choice);
			if(choice == 1) {
				found = linear_search_word(word_array, n, word);
			}
			else {
				sort_word(word_array, n);
				found = binary_search_word(word_array, n, word);
			}
			if(found)
				printf("%s FOUND in the array.\n", word);
			else
				printf("%s NOT FOUND in the array.\n", word);
			break;
		case 3:
			printf("Enter the length of array.\n");
			scanf("%d", &n);
			float *float_array = (float *)malloc(n * sizeof(float));
			fill_float(float_array, n);
			float f;
			printf("Enter the float number you want to find?\n");
			scanf("%f", &f);
			printf("Press 1 for linear search.\n");
			printf("Press 2 for binary search.\n");
			scanf("%d", &choice);
			if(choice == 1) {
				found = linear_search_float(float_array, n, f);
			}
			else {
				sort_float(float_array, n);
				found = binary_search_float(float_array, n, f);
			}
			if(found)
				printf("%.2f FOUND in the array.\n", f);
			else
				printf("%.2f NOT FOUND in the array.\n", f);
			break;
	}
	return 0;
}
