#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct num_info_s {
	char str_number[6];
	int count;
};

char num_str_table[11][6] = {
	"zero", "one", "two", "three", "four", "five",
	"six", "seven", "eight", "nine", "ten"
};

void init_num_info(struct num_info_s *num_info)
{
	int i = 0;
	for (i = 0; i < 11; i++)
	{
		strcpy(num_info[i].str_number, num_str_table[i]);
		num_info[i].count = strlen(num_info[i].str_number);
	}
}

int str_to_int(char * str)
{
	int i;
	for (i = 0; i < 11; i++)
	{
		if (!strcmp(num_str_table[i], str))
			return i;
	}
	return -1;
}

int calculate(char * input1, char * input2, char op)
{
	int a = str_to_int(input1);
	int b = str_to_int(input2);

	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	default:
		return -1;
	}
}

int is_correct(int answer, char * submit_result, struct num_info_s *num_info)
{
	int i = 0;
	int idx = answer;
	char * ch = submit_result;

	while (*ch != '\0')
	{
		for (i = 0; i < strlen(num_info[idx].str_number); i++)
		{
			if (*ch == num_info[idx].str_number[i])
			{
				num_info[idx].str_number[i] = '-1';
				num_info[idx].count--;
			}
		}
		ch++;
	}

	if (num_info[idx].count == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int T, i;
	char input1[8];
	char input2[8];
	char submit_result[10];
	char op;
	int answer;
	struct num_info_s num_info[11];

	fscanf(stdin, "%d", &T);

	for (i = 0; i < T; i++)
	{
		init_num_info(num_info);

		fscanf(stdin, "%s %c %s = %s", input1, &op, input2, submit_result);
		answer = calculate(input1, input2, op);
		if (answer < 0 || answer >10)
			fprintf(stdout, "No\n");
		else if (!is_correct(answer, submit_result, num_info))
			fprintf(stdout, "No\n");
		else
			fprintf(stdout, "Yes\n");

	}

	return 0;
}
