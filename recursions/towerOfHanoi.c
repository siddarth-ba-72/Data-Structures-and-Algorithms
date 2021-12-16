#include <stdio.h>
#include <stdlib.h>

void toh(int n, char A, char B, char C)
{
	if (n == 1)
	{
		printf("Move 1 from %c to %c\n", A, C);
		return;
	}
	toh(n - 1, A, C, B);
	printf("Move %d from %c to %c\n", n, A, C);
	toh(n - 1, B, A, C);
}

int main()
{
	int k;
	printf("Number of piles: ");
	scanf("%d", &k);
	toh(k, 'A', 'B', 'C');
	return 0;
}
