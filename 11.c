#include <stdio.h>
#include <stdlib.h>

/* answer: 70600674 */

/* version 1 */

int main()
{
	FILE *fin = fopen("11.txt", "r");
	int table[20][20];
	int arr[4][4];
	int i, j;
	int left_col = 1;
	int right_col = 1;
	int hprdct = 1;
	int vprdct = 1;
	int major_dprdct = 1;
	int minor_dprdct = 1;
	int hv_max;
	int d_max;
	int max = 0;
	int counter = 0;
	int x = 0;
	int y = 0;
	char flag;

	for (i = 0; i < 20 && flag != EOF; i++)
	{
		for (j = 0; j < 20 && flag != EOF; j++)
		{
			//flag = fgets(s, 3, fin);
			flag = fscanf(fin, "%d", &table[i][j]);
			//table[i][j] = counter;
			//fseek(fin, 1, SEEK_CUR);
		}
		//fseek(fin, 60 - 12, SEEK_CUR);
	}
	//fseek(fin, 4 * (-60) + 3, SEEK_CUR);

	while (x != 17 || y != 17)
	{
		if (y == 17)   y = 0;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				arr[i][j] = table[x + i][y + j];
			}
		}
		y++;
		if (y == 17)   x++; 

		right_col = 1;
		for (i = 0; i < 4; i++)
		{
			right_col *= arr[i][3];
		}

		if (right_col > left_col)
		{
			counter++;
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 4; j++)
				{
					hprdct *= arr[i][j];
					vprdct *= arr[j][i];
					if (i == j)    major_dprdct *= arr[i][j];
					if (i + j == 3)    minor_dprdct *= arr[i][j];
				}
				hv_max = hprdct > vprdct ? hprdct : vprdct;
				hprdct = vprdct = 1;
			}
			d_max = major_dprdct > minor_dprdct ? major_dprdct : minor_dprdct;
			major_dprdct = minor_dprdct = 1;
			max = hv_max > max ? hv_max : max;
			max = d_max > max ? d_max : max;
		}

		left_col = 1;
		for (i = 0; i < 4; i++)
		{
			left_col *= arr[i][0];
		}
	}	
	printf("%d\n%d\n", max, counter);
	return 0;
}
