#include <stdio.h>

/* answer: 76576500 */

/* version ?*/
/*
int main()
{
	int base = 3;
	int tri_num;
	int i, j;
	int counter = 1;
	int found = 0;
	int composite = 0;
	int index = 2;
	int tmp;
	int primes[1000000] = {0};
	int tally[1000000];
	int flag = 0;

	for (i = 0; i < 1000000; i++)
	{
		tally[i] = 1;
	}

	primes[0] = 2;
	primes[1] = 3;
	while (!found)
	{	
		counter = 1;
		base++;
		tri_num = (base*(base + 1)) / 2;
		
		for (i = primes[index - 1] + 1; i <= tri_num / 2; i++)
		{
			for (j = 0; primes[j]*primes[j] <= i && j < index; j++)
			{
				composite = 0;
				if (i % primes[j] == 0)
				{
					composite = 1;
					break;
				}
			}
			if (!composite)
			{
				primes[index++] = i;
			}
		}

		for (i = 0; (i < index) && !flag; i++)
		{
			while (tri_num % primes[i] == 0)
			{
				tally[i] += 1;
				tri_num /= primes[i];
				if (tri_num == 1)    flag = 1;
			}
		}
		flag = 0;

		for (j = 0; j < index; j++)
		{
			counter *= tally[j];
			tally[j] = 1;
		}
		if (counter > 400)    found = 1;

	}
	printf("%d\t%d\n", tmp, counter);
	return 0;
}
*/

/* theory: For every exact divisorup to the square root, 
 * there is a corresponding divisor above the square root
 */
int main()
{
	int tri_num;
	int base = 1;
	int found = 0;
	int counter = 0;
	int i;

	while (!found)
	{
		counter = 0;
		tri_num = (base*(base + 1)) / 2;
		for (i = 1; i*i <= tri_num; i++)
		{
			if (tri_num % i == 0) counter += 2;
		}
		if (counter > 500) found = 1;
		else base++;
	}
	printf("%d\t%d\n", tri_num, counter);
}
