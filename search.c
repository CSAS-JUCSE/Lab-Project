#include <stdio.h>
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
		scanf("%d", &array[i]);
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
int main()
{
	int n, ch;
	printf("Press 1 for integer.\n");
	printf("Press 2 for float.\n");
	printf("Press 3 for words.\n");
	scanf("%d", &ch);
	printf("Enter the length of array.\n");
	scanf("%d", &n);
	switch(ch) {
		case 1:
			int *int_array = (int *)malloc(n * sizeof(int));
			fill_int(int_array, n);
			int num, choice, found;
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
				
		case 2:
			char *word_array[n];
			int i, found;
			for(i = 0; i < n; i++)
				word_array[i] = (char *)malloc(10 * sizeof(char));
			char word[10];
			printf("Enter the word you want to find?\n");
			scanf("%s", word);
			printf("Press 1 for linear search.\n");
			printf("Press 2 for binary search.\n");
			scanf("%d", &choice);
			if(choice == 1) {
				found = linear_search_word(word_array);
			}
			else {
				sort_word(word_array);
				found = binary_search_word(word_array);
			}
			if(found)
				printf("%s FOUND in the array.\n", word);
			else
				printf("%s NOT FOUND in the array.\n", word);
				
		case 3:
			float *float_array = (float *)malloc(n * sizeof(float));
			fill_float(float_array, n);
			int choice, found;
			float num;
			printf("Enter the float number you want to find?\n");
			scanf("%f", &num);
			printf("Press 1 for linear search.\n");
			printf("Press 2 for binary search.\n");
			scanf("%d", &choice);
			if(choice == 1) {
				found = linear_search_float(float_array);
			}
			else {
				sort_float(float_array);
				found = binary_search_float(float_array);
			}
			if(found)
				printf("%f FOUND in the array.\n", num);
			else
				printf("%f NOT FOUND in the array.\n", num);
	}
	return 0;
}
