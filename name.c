#include <stdio.h>
#include <string.h>
#define PRIME 4111

/*Utility program to reverse an integer*/
void reverse(int *arr, int len)
{
	int i, temp;
	for(i = 0; i < len/2; i++) {
		temp = arr[len - 1 - i];
		arr[len - 1 - i] = arr[i];
		arr[i] = temp;
	}
}
/*Utility program to add two large integers stored in two int arrays*/
void arrSum(int *a, int a_len, int *b, int b_len, int *arr)
{
	int i = a_len - 1, j = b_len - 1, carry = 0;
	while(j >= 0) {
		/*Adding the digits of same place and the carry
		and saving it in array |a| which stores the sum*/
		arr[i + 1] = (a[i] + b[j] + carry) % 10;
		carry = (a[i] + b[j] + carry) / 10;
		i--;
		j--;
	}
	while(i >= 0) {
		arr[i + 1] = (a[i] + carry) % 10;
		carry = (a[i] + carry) / 10;
		i--;
	}
	arr[0] = carry;
}
/*Utility function to find the remainder after dividing a large integer
stored in an int array by a predefined PRIME*/
int modulo(int *arr, int arr_len) {
	int i = 0, j = 0, rem = 0, div = 0;
	while(i <= arr_len) {
		/*Finding the dividend at every step of division
		and saving it in div*/
		div = 10 * rem + arr[i++];
		if(i > arr_len)
			break;
		while(div < PRIME){
			div = 10 * div + arr[i++];
			if(i > arr_len)
				break;
		}
		if(i > arr_len)
			break;
		/*rem is the remainder after dividing the div by PRIME
		at every step*/
		rem = div % PRIME; 
	}
	return (rem = div % PRIME);
}
/*Main driver function to convert Name and Surname into large 
integers by juxtaposing integer codes for alphabet and print 
the corresponding converted integer. Cut the large integers 
into two halves and add the two halves. Compute the remainder 
after dividing the by the PRIME*/
int main()
{
	char name[20], surname[20], full_name[40];
	int int_name[40], name_length, i, j, k, nm, iname_length;
	
	printf("Please enter your name: ");
	scanf("%s", name);
	scanf("%s", surname);
	/*Copying name into full_name string*/
	strcpy(full_name, name);
	/*and concatenating the surname string at the end of it*/
	strcat(full_name, surname);
	name_length = strlen(full_name);
	
	for(i = 0, j = 0; i < name_length; i++) {
		
		/*Typecasting a char into an integer*/
		nm = (int)full_name[i];
		int int_char[5], char_len;
		k = 0;
		/*and saving the digits of that integer in reversed order
		into an array*/
		while(nm != 0) {
			int_char[k++] = nm % 10;
			nm /= 10;
		}
		char_len = k;
		/*then, reversing the array to get the original integer*/
		reverse(int_char, char_len);
		
		/*saving it at the end of the integer array which stores
		the integer code of all the char in the full_name*/
		for(k = 0; k < char_len; k++) {
			int_name[j + k] = int_char[k];
		}
		j += k;
	}
	iname_length = j;
	
	printf("The name converted to integer looks like\n\n");
	for(i = 0; i < iname_length; i++)
		printf("%d", int_name[i]);
	printf("\n\n");
	
	int half1[20], half2[20], half_len1, half_len2, sum_arr[30];
	j = 0;
	/*Slicing the integer array for full_name into two parts,
	saving both the parts in half1 and half2*/
	for(i = 0; i < iname_length/2; i++)
		half1[j++] = int_name[i];
	half_len1 = j;
	j = 0;
	for( ; i < iname_length; i++)
		half2[j++] = int_name[i];
	half_len2 = j;
	/*printing both halves*/
	printf("After slicing the number into two halves, the two halves look like\n\n");
	for(i = 0; i < half_len1; i++)
		printf("%d", half1[i]);
	printf(" + ");
	for(i = 0; i < half_len2; i++)
		printf("%d", half2[i]);
	printf("\n\n");
	
	/*Adding the two halves and saving them in sum_arr*/
	arrSum(half1, half_len1, half2, half_len2, sum_arr);
	printf("Adding the two halves the number becomes\n\n");
	i = 0;
	/*printing sum_arr*/
	while(sum_arr[i] == 0)
		i++;
	for( ; i <= half_len1; i++)
		printf("%d", sum_arr[i]);
	printf("\n\n");
	
	/*Printing the remainder after dividing the sum_arr integer
	by the predefined PRIME*/
	printf("The remainder after dividing the sum by %d is\n\n", PRIME);
	printf("%d\n", modulo(sum_arr, half_len1));
	return 0;
}
