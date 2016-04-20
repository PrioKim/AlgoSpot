#include <stdio.h>

#define SQUARE(x) ((x)*(x))

typedef struct pos{
	int x, y, r;
};

int main()
{
	int T;
	struct pos turret1, turret2;
	int squared_r_sum;
	int squared_distance;
	int squared_r_sub;
	int answer;

	fscanf(stdin, "%d", &T);
	while (T--){
		fscanf(stdin, "%d %d %d %d %d %d", &turret1.x, &turret1.y, &turret1.r
										, &turret2.x, &turret2.y, &turret2.r);
		
		squared_r_sum = SQUARE(turret1.r + turret2.r);
		squared_r_sub = SQUARE(turret1.r - turret2.r);
		squared_distance = SQUARE(turret1.x - turret2.x) + SQUARE(turret1.y - turret2.y);
		

		if (squared_distance == 0 && squared_r_sub == 0)
			answer = -1;
		else if (squared_distance > squared_r_sub && squared_distance < squared_r_sum)
			answer = 2;
		else if (squared_distance == squared_r_sub || squared_distance == squared_r_sum)
			answer = 1;
		else
			answer = 0;

		fprintf(stdout, "%d\n", answer);
	}

	return 0;
}