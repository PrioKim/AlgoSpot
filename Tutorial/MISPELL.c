#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void del_char(int del_idx, char * str)
{
	int i;

	for (i = del_idx-1; i < strlen(str); i++)
	{
		str[i] = str[i + 1];
	}
}


int main()
{
	int testcase_num, i;
	int del_idx;
	char str[81];


	fscanf(stdin, "%d", &testcase_num);

	for (i = 0; i < testcase_num; i++)
	{
		fscanf(stdin, "%d %s", &del_idx, str);
		del_char(del_idx, str);
		fprintf(stdout, "%d %s\n", i + 1, str);
	}

	return 0;
}