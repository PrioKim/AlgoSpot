#include<stdio.h>
#include<string.h>

int monCheck(int mon)
{
	int limit = 0;

	if (mon == 0)
	{
		mon = 12;
	}

	switch (mon)
	{
	case 1:
		//      if ((day>0&& day<32))
		limit = 31;
		break;
	case 2:
		//      if ((day>0 && day< 29))
		limit = 28;
		break;
	case 3:
		//      if ((day>0 && day<32))
		limit = 31;
		break;
	case 4:
		//      if ((day>0 && day<31))
		limit = 30;
		break;
	case 5:
		//      if ((day>0 && day<32))
		limit = 31;
		break;
	case 6:
		//      if ((day>0 && day<31))
		limit = 30;
		break;
	case 7:
		//      if ((day>0 && day<32))
		limit = 31;
		break;
	case 8:
		//      if ((day>0 && day<32))
		limit = 31;
		break;
	case 9:
		//      if ((day>0 && day<31))
		limit = 30;
		break;
	case 10:
		//      if ((day>0 && day<32))
		limit = 31;
		break;
	case 11:
		//      if ((day>0 && day<31))
		limit = 30;
		break;
	case 12:case 0:
		//      if ((day>0 && day<32))
		limit = 31;
		break;
	}

	return limit;

}
int weekCheck(char week[10])
{
	int weekNum = 0;
	char constWeek[7][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	for (int i = 0; i < 7; i++)
	{

		if (!strcmp(constWeek[i], week))
			weekNum = i;

	}
	return weekNum;
}
int startCheck(int day, int weekNum, int prelimt)
{
	int start = 0;

	start = day - weekNum;
	if (start <= 0)
	{
		start = prelimt - weekNum + day;
	}

	return start;

}

int main()
{
	int T = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int mon = 0;
		int day = 0;
		int limit = 0;
		int prelimit = 0;
		int start = 0;
		int out = 0;
		char week[10] = { 0, };
		int weekNum = 0;
		//      char constWeek[7][10] = { 0, };

		scanf("%d %d %s", &mon, &day, week);
		if (0>mon | mon > 12)
			break;

		limit = monCheck(mon);
		weekNum = weekCheck(week);
		start = startCheck(day, weekNum, monCheck(mon - 1));

		for (int i = 0; i < 7; i++)
		{
			out = start + i;
			if (out >= monCheck(mon - 1) + 1)
			{
				out = out - monCheck(mon - 1);
			}
			printf("%d ", out);
		}
		printf("\n");
	}
}