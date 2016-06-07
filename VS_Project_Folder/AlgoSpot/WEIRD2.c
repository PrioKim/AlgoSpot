#include <stdio.h>
#include <stdlib.h>

#define MAX_DIVISOR_NUM	100

void init_proper_divisor(int *proper_divisor)
{
	int i = 0;
	for (i = 0; i < MAX_DIVISOR_NUM; i++)
	{
		proper_divisor[i] = 0;
	}
}

int search_proper_divisor(int input, int *sum, int *proper_divisor)
{
	int i = 0, idx = 1;
	*sum = 0;
	proper_divisor[0] = 1;

	for (i = 2; i*i <= input; i++)
	{
		if (input % i == 0)
		{
			proper_divisor[idx] = i;
			idx++;
			(*sum) += i;
		}
	}

	return idx + 1;
}

int is_not_weird_num(int input, int divisor_num, int *proper_divisor) 
{
	int i = 0, j = 0, r;
	
	int ** is_correct_table = (int **)malloc(sizeof(int *) * (input + 1));
	for (i = 0; i < input + 1; i++)
		is_correct_table[i] = (int *)malloc(sizeof(int) * (divisor_num + 1));

	for (i = 0; i <= divisor_num; i++)
		is_correct_table[0][i] = 1;

	for (i = 1; i <= input; i++)
		is_correct_table[i][0] = 0;

	for (i = 1; i <= input; i++)
		for (j = 1; j <= divisor_num; j++)
		{
			is_correct_table[i][j] = is_correct_table[i][j - 1];
			if (i >= proper_divisor[j - 1])
			{
				is_correct_table[i][j] = is_correct_table[i][j] ||
					is_correct_table[i - proper_divisor[j - 1]][j - 1];
			}
		}

	r = is_correct_table[input][divisor_num];

	for (i = 0; i < input + 1; i++)
		free(is_correct_table[i]);

	free(is_correct_table);

	return r;
}

int main()
{
	int C, i, input, sum, divisor_num;
	int proper_divisor[MAX_DIVISOR_NUM];

	fscanf(stdin, "%d", &C);

	for (i = 0; i < C; i++)
	{
		fscanf(stdin, "%d", &input);
		init_proper_divisor(proper_divisor);
		divisor_num = search_proper_divisor(input, &sum, proper_divisor);

		if (sum <= input)
		{
			fprintf(stdout, "not weird\n");
		}
		else
		{
			if (!is_not_weird_num(input, divisor_num, proper_divisor))
				fprintf(stdout, "weird\n");
			else
				fprintf(stdout, "not weird\n");
		}
	}

	return 0;
}