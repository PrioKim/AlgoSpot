#include <stdio.h>
#include <string.h>

int table[1000001];

int sum(int pos){
	++pos;
	int ret = 0;
	while (pos > 0){
		ret += table[pos];
		pos &= (pos - 1);
	}
	return ret;
}

void add(int pos, int val)
{
	++pos;
	while (pos < 1000001){
		table[pos] += val;
		pos += (pos & -pos);
	}
}

int get_input()
{
	register int s = 0, ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
	for (s = ch - '0', ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
		s = s * 10 + ch - '0';
	return s;

}

int main()
{
	int C, N, tmp;
    long long output;
	C = get_input();

	while (C--){
		memset(table, 0, sizeof(table));
		output = 0;
		N = get_input();

        for (int i = 0; i < N; i++){
			tmp = get_input();
			output += sum(999999) - sum(tmp);
			add(tmp, 1);
		}

		fprintf(stdout, "%d\n", output);
	}

	return 0;
}