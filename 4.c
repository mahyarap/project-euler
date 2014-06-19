#include <stdio.h>

/* answer: 906609 */

/* version 1 */

int reverse(int a)
{
	int reverse = 0;

	while (a > 0)
	{
		reverse = (10 * reverse) + (a % 10);
		a /= 10;
	}
	return reverse;
}
/*
int main()
{
	int i, j;

	for (i = 999*999; i > 100*100; i--)
	{
		if (i == reverse(i))
		{
			for (j = 999; j > 99; j--)
			{
				if (i % j == 0 && (i / j) / 1000 == 0)
				{
					printf("%d\t%d\n", i, i/j);
					break;
				}
			}
		}
	}
	return 0;
}
*/

/* version 1.1 */
int main()
{
	int i, j;
	int r;
	int flag = 1;

	for (i = 997; i > 99 && flag; i--)
	{
		r = i*1000 + reverse(i);
		for (j = 999; j > 99; j--)
		{
			if (r % j == 0 && (r / j) / 100 != 0 && (r / j) / 1000 == 0)
			{
				printf("%d: %d x %d\n", r, j, r / j);
				flag = 0;
				break;
			}
		}
	}
	return 0;
}
