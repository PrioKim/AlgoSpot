#include <stdio.h>

int fibonacci(int n, int *print_0, int *print_1)
{
	int i = 0;
	int n1, n2, tmp;
	
	if (n == 0) {
		*print_0 = 1;
		*print_1 = 0;
		return 0;
	}
	else if (n == 1) {
		*print_0 = 0;
		*print_1 = 1;
		return 1;
	}

	n1 = 0;
	n2 = 1;

	for (i = 0; i < n; i++) {
		tmp = n2;
		n2 += n1;
		n1 = tmp;
	}

	*print_1 = n1;
	*print_0 = n2 - n1;

	return n2;
}

int main()
{
	int T;
	int n;
	int print_0, print_1;

	fscanf(stdin, "%d", &T);
	while (T--){
		fscanf(stdin, "%d", &n);
		fibonacci(n, &print_0, &print_1);
		fprintf(stdout, "%d %d\n", print_0, print_1);
	}
	return 0;
}