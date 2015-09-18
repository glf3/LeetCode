#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
using namespace std;

const int maxn = 5010;
int proc[maxn][maxn];

class Solution {
public:
    int maxProduct(vector<int>& nums) {
		int n = nums.size();
		if(n == 1) return nums[0];
		vector<int> &a = nums;
		int ans = a[0];
		for(int i = 0; i < n; i++)
			 { proc[i][i] = a[i]; ans = max(ans, a[i]); } 
		
		for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
		{
			proc[i][j] = proc[i][j-1]*a[j];
			ans = max(ans, proc[i][j]);
		}
		return ans;
    }
};

//////////////
Solution g;

int main(void)
{
	vector<int> a;
	a.push_back(-2);
	printf("%d\n", g.maxProduct(a));
	system("pause");
	return 0;
}
