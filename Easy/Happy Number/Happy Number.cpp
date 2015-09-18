#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <stack>
using namespace std;

int calculate(int n)
{
	int ans = 0;
	while(n)
	{
		ans += (n%10)*(n%10);
		n /= 10;
	}
	return ans;
}

class Solution {
public:
    bool isHappy(int n) {
        set<int> vis;
    	vis.insert(n);
        for(;;)
        {
			n = calculate(n);
			if(n == 1) return true;
			if(vis.count(n)) return false;
			vis.insert(n);
		}
		return false;
    }
};

////////////
Solution g;

int main(void)
{
	if(g.isHappy(19))
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
}
