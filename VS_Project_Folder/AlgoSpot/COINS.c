#include <stdio.h>
#include <string.h>

int main()
{
	int T, M, C;
	unsigned int case_num[5001];
	int coin;

	fscanf(stdin, "%d", &T);


	while (T--) {
		fscanf(stdin, "%d %d", &M, &C);
		memset(case_num, 0, sizeof(case_num));

		case_num[0] = 1;
		for (int i = 0; i < C; i++) {
			fscanf(stdin, "%d", &coin);
			for (int j = coin; j <= M; j++){
				case_num[j] = (case_num[j] + case_num[j - coin]) % 1000000007;
			}
		}
		fprintf(stdout, "%d\n", case_num[M]);
	}
	return 0;
}


