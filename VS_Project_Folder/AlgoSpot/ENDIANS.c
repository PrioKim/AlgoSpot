#include <stdio.h>

int main()
{
	int testcaseNum = 0;
	unsigned int input = 0;
	unsigned int output = 0;
	unsigned int tmp = 0;
	unsigned int HEXA_ARR[4] = { 0xFF, 0xFF00, 0xFF0000, 0xFF000000 };
	// 8비트씩 건드리기 위해서 배열 선언
	int i = 0, j = 0, shift_num = 24;

	fscanf(stdin, "%u", &testcaseNum); //read testcaseNum
	for (i = 0; i < testcaseNum; i++)
	{
		output = 0;
		fscanf(stdin, "%u", &input);
		for (j = 0; j < 4; j++)
		{
			tmp = input & HEXA_ARR[j];	// and 연산으로 input에 HEXA_ARR에 해당하는 비트만 남긴다.
			if (j < 2)
			{
				tmp = tmp << shift_num; // 쉬프트연산으로 비트를 이동 시킨후
				shift_num -= 16;
				output |= tmp;			//  or 연산으로 output에 더한다.
			}
			else
			{
				shift_num += 16;
				tmp = tmp >> shift_num;
				output |= tmp;
			}
		}
		fprintf(stdout, "%u\n", output);
	}

	return 0;
}