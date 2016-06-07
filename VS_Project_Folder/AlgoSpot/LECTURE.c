#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_swap(char **a, char **b)
{
	char *c;
	c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int testcase_num = 0, i = 0, j = 0, k = 0;
	char input_str[1000] = { 0, };
	

	char ** input_split_arr = NULL; // 2차월 배열 동적할당하려구
	char ** result_str = NULL;
	int flag = 0;
	int arr_size = 0; // 2차원 배열 크기

	fscanf(stdin, "%d", &testcase_num);
	result_str = (char **)malloc(sizeof(char *) * testcase_num);
	for (j = 0; j < testcase_num; j++)
	{
		result_str[j] = (char *)malloc(sizeof(char) * 1000); // 최대 1000자니까
	}

	for (i = 0; i < testcase_num; i++)
	{
		fscanf(stdin, "%s", input_str);
		arr_size = strlen(input_str) / 2;

		input_split_arr = (char **)malloc(sizeof(char*) * arr_size);
		
		for (j = 0, k = 0; j < arr_size; j++, k += 2)
		{
			input_split_arr[j] = (char *)malloc(sizeof(char) * 3); // NULL 포함 하려구
			input_split_arr[j][0] = input_str[k];
			input_split_arr[j][1] = input_str[k + 1];
			input_split_arr[j][2] = '\0';
		}

		for (j = 0; j < arr_size-1; j++)
		{
			flag = 0;
			for (k = 0; k < arr_size-1-j; k++)
			{
				if (strcmp(input_split_arr[k], input_split_arr[k+1]) > 0)
				{
					flag = 1;
					str_swap(&input_split_arr[k], &input_split_arr[k+1]);
				}
			}
		}

		strcpy(result_str[i], input_split_arr[0]);
		for (j = 1; j < arr_size; j++)
		{
			strcat(result_str[i], input_split_arr[j]);
			free(input_split_arr[j]);
		}
		free(input_split_arr);
	}

	for (i = 0; i < testcase_num; i++)
	{
		fprintf(stdout, "%s\n", result_str[i]);
		free(result_str[i]);
	}
	free(result_str);


	return 0;
}