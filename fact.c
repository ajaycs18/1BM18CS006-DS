#include <stdio.h>
#include <stdlib.h>

long fact(int n) {
	if (n == 1)
		return 1;
	else
		return n * fact(n-1);
}

int main(int argc, char **argv) {
	int num = atoi(argv[1]);
	printf("%ld\n\n", fact(num));
	return 0;
}
