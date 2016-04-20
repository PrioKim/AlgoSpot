#include <stdio.h>
#include <string.h>

const char week_table[7][16] =
{
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

int get_index_day(char * day_week)
{
	int i = 0;
	for (i = 0; i < 7; i++)
		if (!strcmp(day_week, week_table[i]))
			return i;
}

void get_days(int idx, int m, int d, int *output)
{
	int i = 0;
	int tmp_day = d;
	output[idx] = d;


	for (i = idx + 1; i < 7; i++) {
		tmp_day++;
		if ((tmp_day == 29 && m == 2) ||
			(tmp_day == 31 && (m == 4 || m == 6 || m == 9 || m == 11)) ||
			(tmp_day == 32 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))){
			tmp_day = 1;
		}

		output[i] = tmp_day;
	}

	tmp_day = d;

	for (i = idx - 1; i >= 0; i--) {
		tmp_day--;
		if (tmp_day == 0){
			if (m == 3){
				tmp_day = 28;
			}
			else if (m == 5 || m == 7 || m == 10 || m == 12){
				tmp_day = 30;
			}
			else
				tmp_day = 31;
		}
		output[i] = tmp_day;
	}

}

int main()
{
	int T, i, j;
	int m, d;
	char day_week[16];
	int output[7];

	fscanf(stdin, "%d", &T);

	for (i = 0; i < T; i++)
	{
		getchar();
		fscanf(stdin, "%d %d %s", &m, &d, day_week);

		get_days(get_index_day(day_week), m, d, output);

		for (j = 0; j < 7; j++){
			fprintf(stdout, "%d", output[j]);
			if (j == 6)
				fprintf(stdout, "\n");
			else
				fprintf(stdout, " ");
		}
	}

	return 0;
}