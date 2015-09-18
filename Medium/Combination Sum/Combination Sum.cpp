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

set<vector<int> > vis;

void dfs(const vector<int> &a, vector<int> dq, int target, vector<vector<int> > &ans)
{
	if(target == 0)
	{
		sort(dq.begin(), dq.end()); /*去重顺便让答案从小到大排列*/
		if(!vis.count(dq))
			 { ans.push_back(dq); vis.insert(dq); }
		return ;
	}
	else if(target < 0 || a[0] > target) return ;
	else for(int i = 0; i < a.size(); i++)
	{
		target -= a[i];
		dq.push_back(a[i]);
		dfs(a, dq, target, ans);
		target += a[i];
		dq.pop_back();
	}
	return ;
}

vector<vector<int> > process(vector<int> &a, int target)
{
	vector<vector<int> > ans;
	if(a.size() == 0) return ans;
	vis.clear();
	vector<int> dq;
	dfs(a, dq, target, ans);
	return ans;
}

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<int> &a = candidates;
		sort(a.begin(), a.end());
        return process(a, target);
    }
};

////////////////
Solution g;

int main(void)
{
	vector<int> a;
	a.push_back(2), a.push_back(3), a.push_back(6), a.push_back(7);
	vector<vector<int> > ans = g.combinationSum(a, 7);
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
