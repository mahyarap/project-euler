#include <stdio.h>

/* answer 25164150 */

/* version 1 */
int main()
{
	int sumof_squares;
	int squareof_sums;
	int diff;

	squareof_sums = (100*(100 + 1)*(2*100 + 1))/6;
	sumof_squares = ((100*(100 + 1))/2)*((100*(100 + 1))/2);
	diff = sumof_squares - squareof_sums;
	printf("diff: %d\n", diff);
	return 0;
}
