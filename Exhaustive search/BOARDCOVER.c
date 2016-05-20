#include <stdio.h>

void print_board(int board[][20], int H, int W){
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			fprintf(stdout, "%d ", board[i][j]);
		}
		fprintf(stdout, "\n");
	}
}

// 보드에서 왼쪽과 위쪽이 막힌 부분부터 채워나간다고 할 때
// ㄱ자 블록의 경우는 아래와 같은 4가지이다.
// (dx, dy)를 의미하며
// (0, 0)이 왼쪽과 오른쪽이 막힌 구역
int board_case[4][3][2] = {
	{ { 0, 0 }, { 0, 1 }, {-1, 1 } },
	{ { 0, 0 }, { 0, 1 }, { 1, 1 } },
	{ { 0, 0 }, { 0, 1 }, { 1, 0 } },
	{ { 0, 0 }, { 1, 0 }, { 1, 1 } }
};

void init_board(int board[][20]){
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			board[i][j] = -1;
}


// delta는 돌을 놓거나 뺌을 의미 +1, -1
int set_the_spot(int board[][20], int y, int x, int H, int W, int delta){
	if (x < 0 || y < 0 || x >= W || y >= H)
		return 0;

	board[y][x] += delta;
	//printf("board[%d][%d] : %d\n", y, x, board[y][x]);

	if (board[y][x] > 1)
		return 0;

	return 1;
}


int cover_the_board(int board[][20], int H, int W){
	int x = -1, y = -1;
	int r = 0;
	int flag;

	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++)
			if (board[i][j] == 0){
				y = i;
				x = j;
				break;
			}
		if (y != -1)
			break;
	}
	if (y == -1)
		return 1;
	
	for (int style = 0; style < 4; style++){
		flag = 1;
		for (int i = 0; i < 3; i++){
			if (!set_the_spot(board, y + board_case[style][i][1], x + board_case[style][i][0], H, W, 1)){
				flag = 0;
			}
		}
		
		if (flag) {
			r += cover_the_board(board, H, W);
		}
		
		for (int i = 0; i < 3; i++)
			set_the_spot(board, y + board_case[style][i][1], x + board_case[style][i][0], H, W, -1);
	}

	return r;
}

int main()
{
	int C, H, W;
	int board[20][20];
	
	fscanf(stdin, "%d", &C);

	while (C--){
		int white_spot = 0;
		fscanf(stdin, "%d %d", &H, &W);
		init_board(board);

		for (int i = 0; i < H; i++){
			getchar();
			for (int j = 0; j < W; j++){
				char tmp;
				fscanf(stdin, "%c", &tmp);
				if (tmp == '.'){
					white_spot++;
					board[i][j] = 0;
				}
				else if (tmp == '#')
					board[i][j] = 1;
			}
		}

		//print_board(board, H, W);

		if (white_spot % 3 != 0)
			fprintf(stdout, "0\n");
		else
			fprintf(stdout, "%d\n", cover_the_board(board, H, W));
	}
	return 0;
}