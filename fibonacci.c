#include <stdio.h>
typedef long long unsigned ll;

/*Utility function to find the n-th Fibonacci number 
with the iterative method*/
ll fibo_iter(int n)
{
	int i;
	ll a, b, c;
	a = 0, b = 1, c = a + b;
	if(n > 1) {
		for(i = 2; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
	}
	return c;
}
/*Utility function to find the n-th Fibonacci number 
with the recursive method*/
ll fibo_recur(int n)
{
	if(n == 0 || n == 1) {
		return n;
	}
	return fibo_recur(n - 1) + fibo_recur(n - 2);
}
/*Main driver function to generate the n-th Fibonacci 
number iteratively and recursively*/
int main()
{
	int n, ch;
	printf("Enter the value of 'n': ");
	scanf("%d", &n);
	printf("How do you want to find fibonacci(%d)?\n", n);
	printf("Press 1 for iterative method.\n");
	printf("Press 2 for recursive method.\n");
	scanf("%d", &ch);
	if(ch == 1) {
		printf("Fibonacci(%d) is %llu.\n", n, fibo_iter(n));
	}
	else {
		printf("Fibonacci(%d) is %llu.\n", n, fibo_recur(n));
	}
	return 0;
}
