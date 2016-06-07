#include <stdio.h>

typedef unsigned long u64;

#define dm_sector_div64(x, y) ( \
{ \
         unsigned long _res; \
         (x) = div64_u64_rem(x, y, &_res); \
         _res; \
} \
)

u64 div64_u64_rem(u64 dividend, u64 divisor, u64 *remainder)
{
	*remainder = dividend % divisor;
	return dividend / divisor;
}

static u64 next_head(u64 cur_head, u64 smax){
	cur_head += 1;
	return dm_sector_div64(cur_head, smax);
}

int main()
{
	u64 a = 6, b = 1024;

	printf("dm_sector_div64(a, b) : %lu\n", next_head(a, b));

	return 0;
}