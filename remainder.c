#include <stdio.h>
#define PRIME 4111
#define SIZE 100

/*Generating an array of large random integers*/
void generate(long long *arr)
{
	int i, x, y;
	for(i = 0; i < SIZE; i++) {
		x = rand();
		y = rand();
		arr[i] = x * y;
	}
}
/*Utility function to find the remainder after dividing the
numbers by PRIME*/
void calculate(long long *num, int *mod)
{
	int i;
	for(i = 0;i < SIZE; i++)
		mod[i] = num[i] % PRIME;
}
/*utility function to print the table*/
void print_table(long long *num, int *mod)
{
	int i;
	for(i = 0; i < SIZE; i++) {
		printf("\t\t%10lld\t\t\t%4d\n", num[i], mod[i]);
	}
}
int main()
{
	/*Creating an array of large integers with predefined
	SIZE*/
	long long large_int[SIZE];
	int modulo[SIZE], i;
	
	/*Seeding the randomizer*/
	srand(time(NULL));
	/*and generating all the random numbers*/
	generate(large_int);
	
	/*Calculating the remainder of each large numbers after
	dividing it by the predefined PRIME*/
	calculate(large_int, modulo);
	
	/*Printing the table of large integers and remainders*/
	printf("The PRIME number taken to calculate ");
	printf("the remainder after dividing by it is %d\n\n", PRIME);
	printf("\t\tLarge numbers\t\tRemainder after dividing\n\t\t\t\t\t\tby %d\n\n", PRIME);
	print_table(large_int, modulo);
	return 0;
}
