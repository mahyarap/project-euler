#include <stdio.h>


int main()
{
	int num[159] = {0};
	int aux[159] = {0};
	int i, j, k, m;
	int tmp;
	int carry;
	int sum = 0;
	int a = 100;

	aux[158] = num[158] = 1;
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < i; j++)
		{	
			tmp = 0;
			carry = 0;
			for (k = 158; k > -1 + a; k--)
			{
				tmp = aux[k] + num[k] + carry;
				num[k] = tmp % 10;
				carry = tmp / 10;
			}
		}
		a--;
		for (m = 158; m > -1; m--)
		{
			aux[m] = num[m];
		}
	}

	for (i = 0; i < 159; i++)
	{
		sum += num[i];
	}
	printf("%d\n", sum);
	return 0;
}
