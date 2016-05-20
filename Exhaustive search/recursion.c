#include <stdio.h>
#include <string.h>

#define MAXARR 100

void init_picked(int picked[])
{
	memset(picked, -1, sizeof(int) * MAXARR);
}

void print_picked(int picked[])
{
	for (int i = 0; i < MAXARR; i++)
	{
		if (picked[i] == -1)
			break;
		printf("%d ", picked[i]);
	}
	printf("\n");
}

int is_empty(int picked[])
{
	if (picked[0] == -1)
		return 1;
	else
		return 0;
}

int picked_back(int picked[])
{
	int i;
	for (i = 0; i < MAXARR; i++)
	{
		if (picked[i] == -1)
			break;
	}

	return picked[--i];
}

void picked_push_back(int picked[], int value)
{
	int i;
	for (i = 0; i < MAXARR; i++)
	{
		if (picked[i] == -1){
			picked[i] = value;
			break;
		}
	}
	
}

int picked_pop_back(int picked[])
{
	int i;
	for (i = 0; i < MAXARR; i++)
	{
		if (picked[i] == -1)
			break;
	}
	int r = picked[--i];
	picked[i] = -1;

	return r;
}

void pick(int n, int picked[], int toPick)
{
	if (toPick == 0){
		print_picked(picked);
		return;
	}

	int smallest = is_empty(picked) ? 0 : picked_back(picked) + 1;

	for (int next = smallest; next < n; next++) {
		picked_push_back(picked, next);
		pick(n, picked, toPick - 1);
		picked_pop_back(picked);
	}
}


int main()
{
	int picked[MAXARR];
	
	init_picked(picked);
	pick(4, picked, 2);
}