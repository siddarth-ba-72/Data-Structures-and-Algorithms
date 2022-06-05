#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Binary to decimal recursion
int binToDec(int bin)
{
	if (bin == 0)
		return 0;
	return (bin % 10) + 2 * binToDec(bin / 10);
}

int main()
{
	int binNum;
	printf("Binary number: ");
	scanf("%d", &binNum);
	printf("%d \n", binToDec(binNum));
}
