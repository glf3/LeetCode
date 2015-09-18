#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		if(n == 1)
			if(nums[0] == 1)
				return 0;
		if(nums[n-1] != n)
			return n;
		int ans = 0;
		for(int i = 0; i <= n; i++)
			ans ^= i;
        for(int i = 0; i < nums.size(); i++)
        	ans ^= nums[i];
        return ans;
    }
};

////////////////////
Solution g;

int main(void)
{
	vector<int> a;
	a.push_back(2); a.push_back(0);
	printf("%d\n", g.missingNumber(a));
	system("pause");
	return 0;
}
