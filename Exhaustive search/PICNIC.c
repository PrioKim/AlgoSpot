#include <stdio.h>
#include <string.h>

int bitmap_friends[10][10] = { 0, };
int matched_friends[10] = { 0, };

int init_data(){
	memset(bitmap_friends, 0, sizeof(int) * 100);
	memset(matched_friends, 0, sizeof(int) * 10); 
}

int match_friends(int matched_friends[], int n){
	int free_student = -1;

	for (int i = 0; i < n; i++){
		if (!matched_friends[i]){
			free_student = i;
			break;
		}
	}
	
	if (free_student == -1)
		return 1;

	int r = 0;

	for (int i = free_student + 1; i < n; i++){
		if (!matched_friends[i] && bitmap_friends[free_student][i]){
			matched_friends[i] = matched_friends[free_student] = 1;
			r += match_friends(matched_friends, n);
			matched_friends[i] = matched_friends[free_student] = 0;
		}

	}
	return r;
}

int main()
{
	int C, n, m;
	int r;
	fscanf(stdin, "%d", &C);

	while (C--){
		init_data();
		fscanf(stdin, "%d %d", &n, &m);
		for (int i = 0; i < m; i++){
			int f1, f2;
			fscanf(stdin, "%d %d", &f1, &f2);
			bitmap_friends[f1][f2] = bitmap_friends[f2][f1] = 1;
		}

		fprintf(stdout, "%d\n", match_friends(matched_friends, n));
	}

	return 0;
}