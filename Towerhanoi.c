#include <stdio.h>

void towerhanoi(int n, char src, char dest, char aux) {
	if (n == 1) {
		printf("move %d discs from %c to %c\n", n, src, dest);
		return;
	}
	towerhanoi(n-1, src, aux, dest);
	printf("move %d disc from %c to %c\n", n-1, src, dest);
	towerhanoi(n-1, aux, dest, src);
}

int main() {
	towerhanoi(3, 'A', 'C', 'B');
	return 0;
}
