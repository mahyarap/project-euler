#include <stdio.h>

/* answer: 6857 */

/* version 1.1 */

/* every number n can at most have one prime factor greater than sqrt(n) */
int main()
{
	int primes[1000];
	long long num = 600851475143L;
	int index = 1;
	int i, j;
	int prime = 1;
	//int base = 7;

	primes[0] = 3;
	while (num != 1)
	{
		// generate primes
		for (i = primes[index - 1] + 2; !prime; i += 2)
		{
			prime = 1;
			for (j = 0; primes[j]*primes[j] <= i; j++)
			{
				if (i % primes[j] == 0)
				{
					prime = 0;
					break;
				}
			}
			if (prime)	primes[index++] = i;
		}
		prime = 0;

		while (num % primes[index - 1] == 0)
		{
			num /= primes[index - 1];
		}

	}

	printf("%d\t%d\n", primes[index - 1], index);
	return 0;
}

//for (i = primes[index - 1] + 2; i < base; i += 2)
//{
	//prime = 1;
	//for (j = 0; primes[j]*primes[j] <= i; j++)
	//{
		//if (i % primes[j] == 0)
		//{
			//prime = 0;
			//break;
		//}
	//}
	//if (prime)
	//{
		//primes[index++] = i;
	//}
//}
//base += 2;

