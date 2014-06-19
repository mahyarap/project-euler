#include <stdio.h>
#include <math.h>


int main()
{
	//int a, b, c;
	int m = 1;
	int n = 0;
	int i, j, k;
	int flag = 0;

	/*do {
		a = m * m - n * n;
		b = 2 * m * n;
		c = m * m + n * n;
		m++;
		n++;
	} while (a + b + c != 1000);
	*/

	for (i = 0; i < 4 && !flag; i++)
	{
		for (j = 0; j < 4 && !flag; j++)
		{
			m = pow(2, i) * pow(5, j);
			for (n = 1; n < m; n++)
			{
				if ((2 * m * (m + n)) == 1000)
				{
					flag = 1;
					break;
				}
			}
		}
	}

	printf("%d\t%d\t%d\n", m*m - n*n, 2*m*n, m*m + n*n);
	return 0;
}
