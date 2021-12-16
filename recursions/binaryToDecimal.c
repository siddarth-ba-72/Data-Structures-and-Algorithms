#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binToDec(int bin)
{
	int decNum = 0;
	int counter = 0;
	int k = decNum % 10;
	counter++;
	if (k == 1)
		decNum += pow(2, counter);
	return binToDec(bin / 10);
}

int main()
{
	int binNum;
	printf("Binary number: ");
	scanf("%d", &binNum);
	printf("%d \n", binToDec(binNum));
}
