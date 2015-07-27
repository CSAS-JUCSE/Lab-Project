#include <stdio.h>
typedef long long unsigned ll;


ll facto_iter(int n)
{
	int i;
	ll a = 1;
	if(n > 1) {
		for(i = 2; i <= n; i++) {
			a *= i;
		}
	}
	return a;
}
ll facto_recur(int n)
{
	if(n == 0 || n == 1) {
		return 1;
	}
	return n * facto_recur(n - 1);
}
int main()
{
	int n, ch;
	printf("Enter the value of 'n': ");
	scanf("%d", &n);
	printf("How do you want to find %d! ?\n", n);
	printf("Press 1 for iterative method.\n");
	printf("Press 2 for recursive method.\n");
	scanf("%d", &ch);
	if(ch == 1) {
		printf("%d! is %llu.\n", n, facto_iter(n));
	}
	else {
		printf("%d! is %llu.\n", n, facto_recur(n));
	}
	return 0;
}
