#include <stdio.h>

int get_today(int a, int b)
{
	int days = 0;
	
	while (--a){ // 7월 12일이라 치면 6월달까지 월수 구하기
		if (a == 2){
			days += 28;
		}
		else if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12)
			days += 31;
		else
			days += 30;
	}

	days += b;

	return days;
}

void print_weekday(int days){
	int mod = days % 7;
	switch (mod){
	case 0 :
		printf("SUN\n");
		break;
	case 1:
		printf("MON\n");
		break;
	case 2:
		printf("TUE\n");
		break;
	case 3:
		printf("WED\n");
		break;
	case 4:
		printf("THU\n");
		break;
	case 5:
		printf("FRI\n");
		break;
	case 6:
		printf("SAT\n");
		break;
	}
}

int main()
{
	int m, d;
	fscanf(stdin, "%d %d", &m, &d);

	print_weekday(get_today(m, d));
	
	return 0;
}