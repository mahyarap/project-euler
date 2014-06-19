#include <stdio.h>

/* answer: 213168 */
/* version 1 */
/*
int main()
{
	int sum3 = 0;
	int sum5 = 0;
	int sum15 = 0;
	int i;
	int j = 1;

	for (i = 1; 3*i < 1000; i++)
	{
		sum3 += 3*i;
		++j;
	}
	for (i = 1; 5*i < 1000; i++)
	{
		sum5 += i*5;
		++j;
	}
	for (i = 0; i*15 < 1000; i++)
	{
		sum15 += 15*i;
		++j;
	}
	
	printf("sum: %d\ni: %d", sum3 + sum5 - sum15, j);
	return 0;
}
*/

/* version 1.1 */
/*
int main()
{
	int sum = 0;
	int i;

	for (i = 0; 3*i < 1000; i++)
	{
		for (; 5*i < 1000; i++)
		{
			for (; 15*i < 1000; i++)
			{
				sum += -15*i + 5*i + 3*i;
			}
			sum += 5*i + 3*i;
		}
		sum += 3*i;
	}

	printf("sum: %d\ni: %d", sum, i);
	return 0;
}
*/

/* version 1.2 */

int main()
{
	int numberof_3_multiplies = 999/3;
	int numberof_5_multiplies = 999/5;
	int numberof_15_multiplies = 999/15;
	int sum = 0;

	sum += (numberof_3_multiplies*(3 + 999))/2;
	sum += (numberof_5_multiplies*(5 + 995))/2;
	sum -= (numberof_15_multiplies*(15 + 990))/2;
	printf("sum: %d\n", sum);
	return 0;
}
