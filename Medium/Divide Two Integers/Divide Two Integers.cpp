#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

typedef long long LL;
LL abs_(LL x)
{
	if(x < 0)
		return 1LL*-x;
	return x;
}

LL cal(int x, int y)
{
	bool neg1 = 0, neg2 = 0;
	if(x < 0)
		neg1 = 1;
	if(y < 0)
		neg2 = 1;
	LL a = abs_(x), b = abs_(y);
	if(a < b)
		return 0;
	LL ans = 0;
	while(a >= b)
	{
		LL cnt = 0, t = b;
		while(a >= t)
		{
			a -= t;
			t *= 2;
			ans += LL(1<<cnt);
			++cnt;
		}
	}
	if(neg1 && neg2)
		return ans;
	else if(!neg1 && !neg2)
		return ans;
	else
		return -ans;
}

class Solution {
public:
    int divide(int dividend, int divisor) {
		return cal(dividend, divisor);
    }
};

///////////////
Solution g;

int main()
{
	int x, y;
	while(~scanf("%d,%d", &x, &y))
	{
		printf("%d\n", cal(x, y));
	}
	return 0;
}
