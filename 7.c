#include <stdio.h>

/* answer: 104743 */

/* version 1 */

int main()
{
	int prime_set[10001];
	int* ptr = prime_set + 1;
	int index = 2;
	int number = 5;
	int i;
	int flag = 1;
	int key = 0;
	int k = 1;

	prime_set[0] = 2;
	prime_set[1] = 3;
	while (index < 10001)
	{
		/* generate primes */
		for (i = *ptr; i*i <= number; i = *(++ptr))
		{
			if (number % i == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)	prime_set[index++] = number;
		flag = 1;

		if (key)
		{
			number = 6*k - 1;
			key = 0;
		}
		else
		{
			number = 6*k + 1;
			k++;
			key = 1;
		}

		ptr = prime_set + 1;
	}

	printf("prime: %d\tindex: %d\n", prime_set[index - 1], index);
	return 0;
}
