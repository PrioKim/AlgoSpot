#include <stdio.h>

int main()
{
	int testcaseNum = 0;
	unsigned int input = 0;
	unsigned int output = 0;
	unsigned int tmp = 0;
	unsigned int HEXA_ARR[4] = { 0xFF, 0xFF00, 0xFF0000, 0xFF000000 };
	// 8��Ʈ�� �ǵ帮�� ���ؼ� �迭 ����
	int i = 0, j = 0, shift_num = 24;

	fscanf(stdin, "%u", &testcaseNum); //read testcaseNum
	for (i = 0; i < testcaseNum; i++)
	{
		output = 0;
		fscanf(stdin, "%u", &input);
		for (j = 0; j < 4; j++)
		{
			tmp = input & HEXA_ARR[j];	// and �������� input�� HEXA_ARR�� �ش��ϴ� ��Ʈ�� �����.
			if (j < 2)
			{
				tmp = tmp << shift_num; // ����Ʈ�������� ��Ʈ�� �̵� ��Ų��
				shift_num -= 16;
				output |= tmp;			//  or �������� output�� ���Ѵ�.
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