#include <stdio.h>
#include <stdlib.h>
#define MAXN 30000

/*Utility function to fill the input text file with 30000(MAXN)
random numbers ranging from 1 to 30000(MAXN)*/
void fill_random()
{
	/*Creating an input text file in write mode*/
	FILE *fp = fopen("input.txt","w");
	
	/*Creating a pool of integers ranging from 1 to 30000(MAXN)*/
	int i, pool_length, x, idx;
	int *random_pool  = (int *)malloc((MAXN + 1) * sizeof(int));
	for(i = 0; i <= MAXN; i++)
		random_pool[i] = i;
	pool_length = MAXN;
	
	/*Seeding the randomizer*/
	srand(time(NULL));
	for(i = 1; i <= MAXN; i++) {
		/*and randomly selecting an index ranging from 1 to current
		pool_length*/
		idx = rand() % pool_length + 1;
		/*to select the number with that particular index as a unique
		random number*/
		x = random_pool[idx];
		/*writing it in the input file*/
		fprintf(fp, "%d\n", x);
		/*and removing it from the random number pool so that the number
		does not occur again in our list of unique random numbers*/
		random_pool[idx] = random_pool[pool_length];
		/*decreasing the pool_length as well*/
		pool_length -= 1;
	}
	fclose(fp);
}
/*Utility function to print the input file*/
void print_file()
{
	FILE *fp = fopen("input.txt","r");
	int i, x;
	printf("\t\tThe unique random numbers upto 30,000\n");
	for(i = 1; i <= MAXN; i++) {
		fscanf(fp, "%d", &x);
		printf("%d. %d\t", i, x);
	}
}
/*Main driver function to to generate 30,000(MAXN) random integers between 
1 and 30,000(MAXN) without repetitions and store them in a file in character
mode one number per line*/
int main()
{
	fill_random();
	print_file();
	return 0;
}
