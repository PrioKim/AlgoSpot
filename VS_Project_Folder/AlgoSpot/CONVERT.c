#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float convert_m_to_e(char * unit, float m);
float convert_e_to_m(char * unit, float e);
int is_m(char * s);
typedef float(*convert)(char *, float);

int main()
{
	int testcase_num, i;
	float i_value;
	float o_value;
	char unit[4];
	convert conv_fn;

	fscanf(stdin, "%d", &testcase_num);

	for (i = 0; i < testcase_num; i++)
	{
		fscanf(stdin, "%f %s", &i_value, unit);
		
		if (is_m(unit)) conv_fn = convert_m_to_e;
		else conv_fn = convert_e_to_m;

		o_value = conv_fn(unit, i_value);
				
		fprintf(stdout, "%d %.4f %s\n", i + 1, o_value, unit);
	}

	return 0;
}

int is_m(char *s)
{
	if (!strcmp(s, "kg") || !strcmp(s, "l"))
		return 1;

	return 0;
}

float convert_m_to_e(char * unit, float m)
{
	if (!strcmp(unit, "kg"))
	{
		strcpy(unit, "lb");
		return m*2.2046;
	}

	if (!strcmp(unit, "l"))
	{
		strcpy(unit, "g");
		return m*0.2642;
	}
}

float convert_e_to_m(char * unit, float e)
{
	if (!strcmp(unit, "lb"))
	{
		strcpy(unit, "kg");
		return e*0.4536;
	}

	if (!strcmp(unit, "g"))
	{
		strcpy(unit, "l");
		return e*3.7854;
	}
}