#include <stdio.h>

/* answer: 1366 */

/* version 1 */

int main()
{
	/* number of digits = [log(2^1000)] + 1 */
	short the_number[302] = {0};
	int i, j;
	int tmp;
	int carry = 0;
	int sum = 0;
	int tail = 300;

	the_number[301] = 1;
	for (i = 0; i < 1000; i++)
	{
		for (j = 301; j > tail; j--)
		{
			tmp = the_number[j] * 2;
			if (tmp < 10)
			{
				the_number[j] = tmp;
				the_number[j] += carry;
				carry = 0;
			}
			else
			{
				the_number[j] = tmp - 10;
				the_number[j] += carry;
				carry = 1;
			}
		}
		if (carry == 1)
		{
			the_number[tail--] += 1;
			carry = 0;
		}
	}

	for (i = tail + 1; i < 302; i++)
	{
		printf("%d", the_number[i]);
		sum += the_number[i];
	}

	printf("\nsum: %d\n", sum);
	return 0;
}
