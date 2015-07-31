#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Utility function to fill integer array with numbers given
by users*/
void fill_int(int *array, int len)
{
	printf("Please enter %d integers each followed by a space.\n");
	int i;
	for(i = 0; i < len; i++) {
		scanf("%d", &array[i]);
	}
}
/*Utility finction to linearly search the integer array for num*/
int linear_search_int(int *array, int len, int num)
{
	int i;
	for(i = 0; i < len; i++) {
		if(array[i] == num)
		return 1;
	}
	return 0;
}
/*Utility function to sort an integer array*/
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
/*Utility finction to linearly search the integer array for num*/
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
/*Utility function to fill float array with numbers given
by users*/
void fill_float(float *array, int len)
{
	printf("Please enter %d floats each followed by a space.\n");
	int i;
	for(i = 0; i < len; i++) {
		scanf("%f", &array[i]);
	}
}
/*Utility function to linearly search the float array for f*/
int linear_search_float(float *array, int len, float num)
{
	int i;
	for(i = 0; i < len; i++) {
		if(array[i] == num)
		return 1;
	}
	return 0;
}
/*Utility function to sort a flaot array*/
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
/*Utility function to linearly search the float array for f*/
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
/*Utility function to fill a word array with user given words*/
void fill_words(char **array, int len)
{
	printf("Please enter %d words each followed by a newline.\n");
	int i;
	for(i = 0; i < len; i++) {
		scanf("%s", array[i]);
	}
}
/*Utility function to linearly search the word array for the 
user given word*/
int linear_search_word(char **array, int len, char *word)
{
	int i;
	for(i = 0; i < len; i++) {
		if(strcmp(array[i], word) == 0)
		return 1;
	}
	return 0;
}
/*Utility function to sort aword array*/
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
/*Utility function to binarysearch the word array for word*/
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
/*Main driver function for linear search and binary search for 
searching integers, floating point numbers and words in arrays 
of respective types*/
int main()
{
	int n, ch, choice, found;
	/*Printing three choices for integer, float or words*/
	printf("Press 1 for integer.\n");
	printf("Press 2 for words.\n");
	printf("Press 3 for floats.\n");
	scanf("%d", &ch);
	switch(ch) {
		case 1:
			/*Creating an array of integers and filling it with numbers
			given by users*/
			printf("Enter the length of array.\n");
			scanf("%d", &n);
			int *int_array;
			int_array = (int *)malloc(n * sizeof(int));
			fill_int(int_array, n);
			
			/*Asking the user to input the number which we need to find*/
			int num;
			printf("Enter the number you want to find?\n");
			scanf("%d", &num);
			
			/*Printing two choices for linear and binary search respectively*/
			printf("Press 1 for linear search.\n");
			printf("Press 2 for binary search.\n");
			scanf("%d", &choice);
			if(choice == 1) {
				/*Linear search int_array for the number num*/
				found = linear_search_int(int_array, n, num);
			}
			else {
				/*In case of binary search first we sort the int_array*/
				sort_int(int_array, n);
				/*and then binary search for num*/
				found = binary_search_int(int_array, n, num);
			}
			if(found)
				printf("%d FOUND in the array.\n", num);
			else
				printf("%d NOT FOUND in the array.\n", num);
			break;
		
		
		case 2:
			/*Creating a 2D array of words and filling it with numbers
			given by users*/
			printf("Enter the length of array.\n");
			scanf("%d", &n);
			char **word_array;
			word_array = (char **)malloc(n * sizeof(char *));
			int i;
			for(i = 0; i < n; i++)
				word_array[i] = (char *)malloc(10 * sizeof(char));
			fill_words(word_array, n);
			
			/*Asking the user to input the word which we need to find*/
			char word[10];
			printf("Enter the word you want to find?\n");
			scanf("%s", word);
			
			/*Printing two choices for linear and binary search respectively*/
			printf("Press 1 for linear search.\n");
			printf("Press 2 for binary search.\n");
			scanf("%d", &choice);
			if(choice == 1) {
				/*Linear search word_array for the char array word*/
				found = linear_search_word(word_array, n, word);
			}
			else {
				/*In case of binary search first we sort the word_array*/
				sort_word(word_array, n);
				/*and then binary search for num*/
				found = binary_search_word(word_array, n, word);
			}
			if(found)
				printf("%s FOUND in the array.\n", word);
			else
				printf("%s NOT FOUND in the array.\n", word);
			break;
		
		
		case 3:
			/*Creating an array of floats and filling it with numbers
			given by users*/
			printf("Enter the length of array.\n");
			scanf("%d", &n);
			float *float_array = (float *)malloc(n * sizeof(float));
			fill_float(float_array, n);
			
			/*Asking the user to input the number which we need to find*/
			float f;
			printf("Enter the float number you want to find?\n");
			scanf("%f", &f);
			
			/*Printing two choices for linear and binary search respectively*/
			printf("Press 1 for linear search.\n");
			printf("Press 2 for binary search.\n");
			scanf("%d", &choice);
			if(choice == 1) {
				/*Linear search float_array for the number f*/
				found = linear_search_float(float_array, n, f);
			}
			else {
				/*In case of binary search first we sort the float_array*/
				sort_float(float_array, n);
				/*and then binary search for f*/
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
