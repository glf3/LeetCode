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

const int maxn = 10010;
int dp[maxn];

class Solution {
public:
    int rob(vector<int> &num) {
		int n = num.size();
		if(n == 0) return 0;
		if(n == 1) return num[0];
		else if(n == 2) return max(num[0], num[1]);
		dp[0] = num[0]; dp[1] = max(num[0], num[1]);
		int ans = 0;
        for(int i = 2; i < n; i++)
        	{ dp[i] = max(dp[i-1], dp[i-2]+num[i]); ans = max(ans, dp[i]); }
        return ans;
    }
};

///////////////
Solution g;

int main(void)
{
	vector<int> num;
	num.push_back(1); num.push_back(2); num.push_back(3); num.push_back(4); 
	printf("%d\n", g.rob(num));
	system("pause");
	return 0;
}
