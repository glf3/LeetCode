#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> &a = nums;
		int n = a.size();
		int left[n], right[n];
		vector<int> ans(n);
		
		left[0] = 1;
        for(int i = 1; i < n; i++)
        	left[i] = left[i-1]*a[i-1];
        
        right[n-1] = 1;
        for(int i = n-1; i >= 0; i--)
		{
			if(i != n-1)
				right[i] = right[i+1]*a[i+1];
			ans[i] = left[i]*right[i];
		}
        return ans;
    }
};

////////////////////
Solution g;

int main(void)
{
	vector<int> a;
	a.push_back(1); a.push_back(2);
	a.push_back(3);	a.push_back(4);
	g.productExceptSelf(a);
	system("pause");
	return 0;
}
