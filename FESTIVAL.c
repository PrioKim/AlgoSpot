//#include <stdio.h>
//
//int main()
//{
//	int C, N, L, tmp_L, sum = 0;
//	int day[1000];
//	double min;
//	double avg = 0.0;
//
//	fscanf(stdin, "%d", &C);
//	
//	while (C--){
//		fscanf(stdin, "%d %d", &N, &L);
//		for (int i = 0; i < N; i++)
//			fscanf(stdin, "%d", &day[i]);
//		min = 100000000000.0;
//		tmp_L = L;
//		while (tmp_L <= N){
//			for (int i = 0; i + tmp_L <= N; i++) {
//				sum = 0;
//
//				for (int j = i; j < i + tmp_L; j++)	{
//					sum += day[j];
//				}
//
//				avg = (double)sum / tmp_L;
//				if (min > avg)
//					min = avg;
//			}
//			tmp_L++;
//		}
//		fprintf(stdout, "%.12f\n", min);
//	}
//	return 0;
//
//}
//


#include <stdio.h>

int main()
{
	int sector = 8196;
	int block_n;

	block_n = sector >> 9;

	printf("%d : block Number\n", block_n);

	sector = block_n << 9;
	printf("%d : sector\n", sector);

	return 0;
}
