#include <stdio.h>

/* answer: 4613732 */

/*version 1 */
/*
int main()
{
	int x = 1;
	int y = 2;
	int z;
	int i;
	long long int sum = 0;

	//for (i = 0; i < 10; i++)
	//{
		//z = x + y;
		//x = y;
		//y = z;
		//printf("%d\n", z);
	//}

	x = 1;
	y = 2;

	while (y < 4000000)
	{
		if (y % 2 == 0)    sum += y;
		y = y + x;
		x = y - x;
	}

	printf("%lld\n", sum);
	return 0;
}
*/

int main()
{
	int x = 1;
	int y = 2;
	long long int sum = 2;

	while (y < 4000000)
	{
		sum += y;
		y = y + x;
		x = y - x;
		y = y + x;
		x = y - x;
		y = y + x;
		x = y - x;
	}

	printf("%lld\n", sum);
	return 0;
}
