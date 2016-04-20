#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int building_num;
	int i, j;
	int goal, tmp_power, sum_power = 0;

	fscanf(stdin, "%d", &building_num); 

	for (i = 0; i < building_num; i++)
	{
		sum_power = 0;

		fscanf(stdin, "%d", &goal);

		for (j = 0; j < 9; j++)
		{
			fscanf(stdin, "%d", &tmp_power);
			sum_power += tmp_power;
		}

		if (sum_power <= goal)	
			fprintf(stdout, "YES\n");
		else   
			fprintf(stdout, "NO\n");
	}

	return 0;
}