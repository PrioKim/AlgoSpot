#include <stdio.h>

int get_syndrome(int *input)
{
	int one = 1;
	int tmp = 0;
	int syndrome = 0;

	syndrome = (input[0] ^ input[2] ^ input[4] ^ input[6]);
	syndrome |= (input[1] ^ input[2] ^ input[5] ^ input[6]) << 1;
	syndrome |= (input[3] ^ input[4] ^ input[5] ^ input[6]) << 2;

	return syndrome;
}

int main()
{
	int T, i, j;
	int input[7];
	int syndrome;
	int one = 1;

	fscanf(stdin, "%d", &T);
	
	for (i = 0; i < T; i++)
	{
		one = 1;
		getchar();
		for (j = 0; j < 7; j++)
			input[j] = fgetc(stdin) -'0';
		
		syndrome = get_syndrome(input);
		if (0 != syndrome)
		{
			if (input[syndrome - 1] == 0)
				input[syndrome - 1] = 1;
			else
				input[syndrome - 1] = 0;
		}

		fprintf(stdout, "%d%d%d%d\n", input[2], input[4], input[5], input[6]);
	}


	return 0;
}