#include <stdio.h>

/* answer: 4782 */

/* version 1 */

// ToDo: use Binet's formula

int main()
{
	int fn[1000] = {0};
	int fn_1[1000] = {0};
	int fn_2[1000] = {0};
	int i;
	int index;
	int carry = 0;
	int tmp;
	int counter = 2;

	fn_1[999] = 1;
	fn_2[999] = 1;
	index = 998;
	while (index > -1)
	{
		carry = 0;
		for (i = 999; i > index; i--)
		{
			tmp = fn_1[i] + fn_2[i] + carry;
			fn[i] = tmp % 10;
			carry = tmp / 10;
		}
		if (carry)
		{
			fn[index] = carry;
			index--;
		}

		for (i = 999; i > index; i--)
		{
			fn_1[i] = fn_2[i];
			fn_2[i] = fn[i];
		}
		counter++;
	}

	for (i = 0; i < 1000; i++)
	{
		printf("%d", fn[i]);
	}
	printf("\n%d\n", counter);
	return 0;
}
