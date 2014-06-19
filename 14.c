#include <stdio.h>
#include <math.h>

/* answer: 837799 */

/* version 1 */

int main()
{
	int num;
	unsigned long  tmp;
	int numberof_terms = 1;
	int max = 0;
	int target;
	
	for (num = 999999; num > 500000; num--)
	{
		tmp = num;
		while (tmp != 1)
		{
			/* does'n optimize at all! */
			/*if (log2(tmp) - (int)log2(tmp) == 0)
			{
				numberof_terms += log2(tmp) + 1;
				break;
			}*/
			if (tmp % 2 == 0)    tmp /= 2;
			else    tmp = 3 * tmp + 1;
			numberof_terms++;
		}
		if (numberof_terms > max)
		{
			max = numberof_terms;
			target = num;
		}
		numberof_terms = 0;
	}
	printf("target: %d\tterms: %d\n", target, max);
	return 0;
}


/* backtracking solution, not working yet */
/*
int main()
{
	long long int powof_two = 1;
	int i;

	for (i = 0; i < 10; i++)
	{
		powof_two *= 2;
	}

	while ((powof_two - 1) % 3 != 0)
	{
		powof_two /= 2;
	}

	i = 0;
	while (i < 500)
	{
		if ((powof_two - 1) % 3 == 0)
		{
			powof_two = (powof_two - 1) / 3;
			continue;
		}
		else
		{
			powof_two *= 2;
		}
		i++;
	}
	printf("%lld\n", powof_two);
}
*/
