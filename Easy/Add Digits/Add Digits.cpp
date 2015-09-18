#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
using namespace std;

int add(int sum)
{
	int ans = 0;
	while(sum >= 10)
	{
		ans += sum%10;
		sum /= 10;
	}
	ans += sum;
	return ans;
}

class Solution {
public:
    int addDigits(int num) {
        for(;;)
        {
			if(num < 10) break;
			else
				num = add(num);
		}
		return num;
    }
};

//////////////
Solution g;

int main(void)
{
	printf("%d\n", g.addDigits(10));
	system("pause");
}
