#include <stdio.h>
#include <stdlib.h>

long fib(int n) {
	if (n == 1 || n == 0)
		return 1;
	else
		return fib(n-1) + fib(n-2);
}

int main(int argc, char **argv) {
	int num = atoi(argv[1]);
	long result = 0;
	result = fib(num);
	printf("%ld\n\n", result);
	return 0;
}
