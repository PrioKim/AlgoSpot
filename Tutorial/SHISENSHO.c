#include <stdio.h>

int main()
{
	int T;
	int W, H;
	char board[50][50] = { '.', };

	fscanf(stdin, "%d", &T);

	while (T--) {
		fscanf(stdin, "%d %d\n", &W, &H);
		
        for (int i = 1; i < W-1; i++){
			for (int j = 1; j < H-1; j++){
				board[i][j] = getchar();
			}
		}
	}
}
