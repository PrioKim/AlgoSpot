#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char * i_str, char * o_str)
{
	int len = strlen(i_str);
	int i, j;

	for (i = 0; i < len; i++)
	{
		if (i % 2 == 0)
		{
			o_str[i / 2] = i_str[i];
		}
		else
		{
			o_str[(len / 2) + len % 2 + (i / 2)] = i_str[i];
		}
	}
	o_str[len] = '\0';
}

int main()
{
	int testcase_num, i;
	char in_str[101];
	char out_str[101];


	fscanf(stdin, "%d", &testcase_num);

	for (i = 0; i < testcase_num; i++)
	{
		fscanf(stdin, "%s", in_str);
		encrypt(in_str, out_str);
		fprintf(stdout, "%s\n", out_str);
	}

	return 0;
}