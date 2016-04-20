#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
	return *(int *)b - *(int *)a;
}

int main()
{
	int c;
	int n;
	int output;
	int i, j = 0;

	fscanf(stdin, "%d", &c);

	while (c--){
		int strlen[100] = { 0, };
		output = 0;

		fscanf(stdin, "%d", &n);

		for (i = 0; i < n; i++){
			fscanf(stdin, "%d", &strlen[i]);
		}
        
		while(n - 1){
			qsort((void *)strlen, n, sizeof(int), cmp);

			strlen[n - 2] = strlen[n - 1] + strlen[n - 2];
			output += strlen[--n - 1];
		}
        
		fprintf(stdout, "%d\n", output);
	}
}

