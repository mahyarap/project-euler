#include <stdio.h>

/* answer: 142913828922 */

/* version 1.1 */
int main()
{
	long int prime_set[1999999];
	long int *ptr = prime_set + 1;
	long int number = 5;
	unsigned long long  sum = 5; /* prevent overflow */
	int index = 2;
	int i;
	int flag = 1;
	int key = 0;
	int k = 1;

	prime_set[0] = 2;
	prime_set[1] = 3;
	while (number < 2000000)
	{
		for (i = *ptr; i*i <= number; i = *(++ptr))
		{
			if (number % i == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			prime_set[index++] = number;
			if (number < 2000000)
				sum += number;
			//else    break;
		}
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

	printf("prime: %ld\tindex: %d\tsum: %lld\n", prime_set[index - 1], index, sum);
	return 0;
}
