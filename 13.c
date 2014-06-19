#include <stdio.h>
#include <string.h>

/* answer: 5537376230390876637302048746832985971773659831892672 */

/* version 1 */

/* TODO: How many numbers should be calculated to obtain n correct digits ? */

int main()
{
	FILE *fin = fopen("13.txt", "r");
	int table[100][52];
	int sum[52] = {0};
	int partial_sum = 0;
	int carry = 0;
	int i, j;
	char flag;

	for (i = 0; i < 100 && flag != EOF; i++)
	{
		for (j = 0; j < 52 && flag != EOF; j++)
		{
			if (j < 2)
			{
				table[i][j] = 0;
				continue;
			}
			flag = fgetc(fin);
			if (flag >= '0' && flag <= '9')    table[i][j] = flag - '0';
			else if (flag == '\n')    j--;	
			else if (flag == EOF)    continue;
		}
	}
	fclose(fin);

	for (i = 0; i < 100; i++)
	{
		partial_sum = 0;
		carry = 0;
		for (j = 12; j > -1; j--)
		{
			partial_sum = sum[j] + table[i][j] + carry;
			sum[j] = partial_sum % 10;
			carry = partial_sum / 10;
		}
	}

	for (i = 0; i < 52; i++)
	{
		printf("%d", sum[i]);
	}
	printf("\n");
	return 0;
}
