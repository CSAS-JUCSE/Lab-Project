#include <stdio.h>
#include <stdlib.h>
#define MAXN 30000

void fill_random()
{
	FILE *fp = fopen("input.txt","w");
	
	int i, pool_length, x, idx;
	int *random_pool  = (int *)malloc((MAXN + 1) * sizeof(int));
	for(i = 0; i <= MAXN; i++)
		random_pool[i] = i;
	pool_length = MAXN;
	
	srand(time(NULL));
	for(i = 1; i <= MAXN; i++) {
		idx = rand() % pool_length + 1;
		x = random_pool[idx];
		fprintf(fp, "%d\n", x);
		random_pool[idx] = random_pool[pool_length];
		pool_length -= 1;
	}
	fclose(fp);
}
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
int main()
{
	fill_random();
	print_file();
	return 0;
}
