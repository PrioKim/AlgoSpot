#include <stdio.h>
#include <stdlib.h>

#define	MIN(x, y)	((x)>(y)?(y):(x))
#define	MAX(x, y)	((x)<(y)?(y):(x))

struct mul_buf{
	int * arr;
	int size;
};

struct mul_buf normalize(struct mul_buf a)
{
	struct mul_buf ret;
	ret.size = a.size + 1;
	ret.arr = (int *)malloc(sizeof(int) * (ret.size));

	for (int i = 0; i < a.size; i++)
		if (a.arr[i] < 0){
			a.arr[i + 1]--;
			a.arr[i] + 10;
		}
		else{
			a.arr[i + 1] += a.arr[i] / 10;
			a.arr[i] %= 10;
		}
	
	free(a.arr);
	return ret;

}

struct mul_buf mul(struct mul_buf a, struct mul_buf b)
{
	struct mul_buf ret;
	ret.size = a.size + b.size + 1;
	ret.arr = (int *)malloc(sizeof(int) * (ret.size));

	for (int i = 0; i < a.size; i++)
		for (int j = 0; j < b.size; j++)
			ret.arr[i + j] = a.arr[i] * b.arr[j];

	free(a.arr);
	free(b.arr);

	ret = normalize(ret);

	return ret;
}


struct mul_buf split_arr(struct mul_buf buf, int start, int end)
{
	struct mul_buf ret;
	ret.size = end - start + 1;
	ret.arr = (int *)malloc(sizeof(int)*ret.size);

	for (int i = start, j = 0; i < end; i++, j++)
		ret.arr[j] = buf.arr[i];

	return ret;
}

struct mul_buf add_buf(struct mul_buf a, struct mul_buf b, int k)
{
	struct mul_buf ret;
	ret.size = MAX(a.size, b.size) + k;
	ret.arr = (int *)malloc(sizeof(int) * (ret.size));
	
	for (int i = 0; i < a.size; i++)
		ret.arr[i] = a.arr[i];
	free(a.arr);

	for (int i = 0; i < b.size; i++)
		ret.arr[i+k] += b.arr[i];
			
	return ret;
}

struct mul_buf sub_buf(struct mul_buf a, struct mul_buf b)
{
	struct mul_buf ret;
	ret.size = MAX(a.size, b.size) + 1;
	ret.arr = (int *)malloc(sizeof(int) * (ret.size));

	for (int i = 0; i < b.size; i++)
		ret.arr[i] = a.arr[i] - b.arr[i];
	free(a.arr);

	return ret;
}

char * to_string(struct mul_buf a)
{
	char * str = (char *)malloc(sizeof(char) * a.size + 1);
	int i = 0;

	for (i = 0; i < a.size; i++)
		str[i] = '0' + a.arr[a.size - 1 - i];

	str[i] = '\n';
	free(a.arr);

	return str;
}

struct mul_buf from_string(char * str)
{
	struct mul_buf ret;
	ret.size = strlen(str);
	ret.arr = (int *)malloc(sizeof(int) * ret.size);

	for (int i = 0; i < ret.size; i++)
		ret.arr[ret.size - i - 1] = str[i] - '0';
	
	free(str);
	
	return ret;
}

struct mul_buf karatsuba(struct mul_buf a, struct mul_buf b)
{
	if (a.size < b.size)
		return karatsuba(b, a); // change a and b because of function sub_from

	if (a.size == 0 || b.size == 0){
		struct mul_buf empty;
		empty.size = 0;
		empty.arr = NULL;
		return empty;
	}

	if (a.size <= 50)
		return mul(a, b);

	int half = a.size / 2;

	struct mul_buf a0 = split_arr(a, 0, half);
	struct mul_buf a1 = split_arr(a, half, a.size);
	struct mul_buf b0 = split_arr(b, 0, MIN(half, b.size));
	struct mul_buf b1 = split_arr(b, MIN(half, b.size), b.size);

	struct mul_buf z2 = karatsuba(a1, b1);
	struct mul_buf z0 = karatsuba(a0, b0);

	a0 = add_buf(a0, a1, 0); // a0 = a0 + a1
	b0 = add_buf(b0, b1, 0); // b0 = b0 + b1

	struct mul_buf z1 = karatsuba(a0, b0); // (a0 + a1) * (b0 + b1)
	z1 = sub_buf(z1, z0); // z1 = z1 - z0
	z1 = sub_buf(z1, z2); // z1 = z1 - z2

	struct mul_buf ret = { NULL, 0 };
	ret = add_buf(ret, z0, 0);  
	ret = add_buf(ret, z1, half);
	ret = add_buf(ret, z2, half + half);
	
	free(a0.arr);
	free(a1.arr);
	free(b0.arr);
	free(b1.arr);
	free(z0.arr);
	free(z1.arr);
	free(z2.arr);

	return ret;
}

int get_male_num(char * str)
{
	int ret = 0;

	int i = 0;
	while (str[i]){
		if (str[i] == 'M')
			ret++;
		i++;
	}

	return ret;
}

struct mul_buf int_to_mul_buf(int a)
{
	int count = 0;
	int temp = a;
	struct mul_buf ret;

	while (temp > 0)
	{
		temp /= 10;
		count++;
	}
	ret.size = count;
	ret.arr = (int *)malloc(sizeof(int) * count);
	for (int i = 10, j = 0; j < count; i *= 10, j++){
		ret.arr[j] = a / i;
	}

	return ret;
}

//int main()
//{
//	int T;
//
//	fscanf(stdin, "%d", &T);
//
//	while (T--){
//		char member[20000];
//		char fan[20000];
//
//		fscanf(stdin, "%s", member);
//		fscanf(stdin, "%s", fan);
//
//		struct mul_buf mul_member = int_to_mul_buf(strlen(member));
//		struct mul_buf mul_fan = int_to_mul_buf(strlen(member));
//		struct mul_buf mul_member_man = int_to_mul_buf(get_male_num(member));
//		struct mul_buf mul_fan_man = int_to_mul_buf(get_male_num(fan));
//	}
//
//	return 0;
//}

int main()
{
	printf("%4s", "");
	return 0;
}