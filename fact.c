#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int fact(int **p, int n)
{
	double sum = (double)0;
	int no_digits = 0;
	int partial_sum;
	int carry;
	int *tmp;
	int index;
	int i, j, k, m;

	/* calculating number of digits */
	if (n > 0)
	{
		for (i = 1; i < n + 1; i++)
		{
			sum += log10(i);
		}
		no_digits = (int)sum + 1;
	}
	else if (n == 0)   no_digits = 1;
	else    return -1;

	*p = malloc(no_digits * sizeof(int));
	if (*p == NULL)    return -1;

	tmp = malloc(no_digits * sizeof(int));
	if (tmp == NULL)    return -1;

	/* initializing */
	for (i = 0; i < no_digits; i++)
	{
		*(*p + i) = 0;
		tmp[i] = 0;
	}
	*(*p + no_digits - 1) = 1;
	tmp[no_digits - 1] = 1;

	/* optimization */
	if (no_digits == 1)    index = -1;
	else    index = no_digits - 2;

	/* main alogrithm */
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			partial_sum = 0;
			carry = 0;
			for (k = no_digits - 1; k > index; k--)
			{
				partial_sum = *(*p + k) + tmp[k] + carry;
				*(*p + k) = partial_sum % 10;
				carry = partial_sum / 10;
			}
			if (index > -1)    index--;
		}
		for (m = 0; m < no_digits; m++)
		{
			tmp[m] = *(*p + m);
		}
	}

	return no_digits;
}

int main()
{
	int *ptr;
	int i;
	int no;

	no = fact(&ptr, 10000);

	for (i = 0; i < no; i++)
	{
		printf("%d", ptr[i]);
	}
	printf("\n");
	free(ptr);
	return 0;
}
