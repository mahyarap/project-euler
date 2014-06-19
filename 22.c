#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* answer: 871198282 */

/* version: 1 */
void merge(char **ptr, int n1, int n2)
{
	char **tmp;
	int i = 0;
	int j1 = 0;
	int j2 = 0;
	int j;

	tmp = malloc((n1 + n2) * sizeof(char *));
	for (j = 0; j < n1 + n2; j++)
	{
		tmp[j] = malloc(20 * sizeof(char));
	}

	while (j1 < n1 && j2 < n2)
	{
		tmp[i++] = strcmp(ptr[j1], ptr[n1 + j2]) <= 0 ? ptr[j1++] : ptr[n1 + j2++];
	}
	while (j1 < n1)
	{
		tmp[i++] = ptr[j1++];
	}
	while (j2 < n2)
	{
		tmp[i++] = (ptr + n1)[j2++];
	}
	for (i = 0; i < n1 + n2; i++)
	{
		ptr[i] = tmp[i];
	}
	free(tmp);
}

void merge_sort(char **ptr, int size)
{
	int n1, n2;

	if (size > 1)
	{
		n1 = size / 2;
		n2 = size - n1;
		merge_sort(ptr, n1);
		merge_sort(ptr + n1, n2);
		merge(ptr, n1, n2);
	}
}

int  main()
{
	FILE *fin;
	char **names;
	int i, j;
	int sum = 0;
	int total = 0;

	fin = fopen("22.txt", "r");
	names = malloc(5163 * sizeof(char*));
	for (i = 0; i < 5163; i++)
	{
		names[i] = malloc(20 * sizeof(char));
	}

	i = 0;
	while (fscanf(fin, "\"%[A-Z]s", names[i++]) != EOF)
	{
		fseek(fin, 2L, SEEK_CUR);
	}

	merge_sort(names, 5163);

	for (i = 0; i < 5163; i++)
	{
		for (j = 0; names[i][j] != '\0'; j++)
		{
			sum += names[i][j] - 'A' + 1;
		}
		total += sum * (i + 1);
		sum = 0;
	}

	printf("%d\n", total);

	free(names);
	fclose(fin);

	return 0;
}
