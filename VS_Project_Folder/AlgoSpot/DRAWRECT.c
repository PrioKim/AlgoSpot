#include <stdio.h>
#include <stdlib.h>

struct point{
	int x;
	int y;
};

int main()
{
	int testcase_num = 0, i = 0, j =0, k = 0;
	struct point points[3] = { 0, };
	struct point * results;

	fscanf(stdin, "%d", &testcase_num);

	results = (struct point *)malloc(testcase_num * sizeof(struct point));

	for (i = 0; i < testcase_num; i++)
	{
		for (j = 0; j < 3; j++)
		{
			fscanf(stdin, "%d %d", &points[j].x, &points[j].y);

			for (k = 0; k < j; k++)
			{
				if (points[j].x == points[k].x)
					points[j].x = points[k].x = 0;

				if (points[j].y == points[k].y)
					points[j].y = points[k].y = 0;
			}
		}
		for (j = 0; j < 3; j++)
		{
			if (points[j].x != 0)
				results[i].x = points[j].x;
			if (points[j].y != 0)
				results[i].y = points[j].y;
		}
	}

	for (i = 0; i < testcase_num;i++)
		fprintf(stdout, "%d %d\n", results[i].x, results[i].y);

	return 0;
}