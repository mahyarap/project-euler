#include <stdio.h>

/**/
/**/

int main()
{
	int num[20];
	int den[20];
	int i, j, k;
	long long n = 1;
	int d = 1;
	int found = 0;

	for (i = 0; i < 20; i++)
	{
		num[i] = i + 21;
	}
	for (i = 0; i < 20; i++)
	{
		den[i] = i + 1;
	}

	for (i = 20; i > 1; i--)
	{
		for (j = 0; j < 20; j++)
		{
			if (num[j] % i == 0)
			{
				for (k = 0; k < 20; k++)
				{
					if (den[k] % i == 0)
					{
						den[k] /= i;
						found = 1;
						break;
					}
				}
				if (found)
				{
					num[j] /= i;
					found = 0;
					//break;
				}
			}
		}
	}

	for (i = 0; i < 20; i++)
	{
		n *= num[i];
		d *= den[i];
	}
	printf("%lld\n", n/d);
}
