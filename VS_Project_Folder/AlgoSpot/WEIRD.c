#include <stdio.h>

#define MAX_DIVISOR_NUM	1000

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
			if (input / i != i)
			{
				proper_divisor[idx] = input/i;
				idx++;
				(*sum) += input / i;
			}
		}
	}
	
	return idx+1;
}

int is_not_weird_num(int input, int divisor_num, int *proper_divisor) // input의 부분집합들을 하나씩 빼가면서 0이 되면 1을 리턴한다.
{
	int i = 0, j = 0;

	if (input == 0)
		return 1;
	if (divisor_num == 0 && input != 0)
		return 0;

	return
		is_not_weird_num(input, divisor_num - 1, proper_divisor) ||
		is_not_weird_num(input - proper_divisor[divisor_num - 1], divisor_num - 1, proper_divisor);
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