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

vector<vector<int> > process(vector<int> &num, int target)
{
	vector<vector<int> > ans;
	vector<int> &a = num;
	sort(a.begin(), a.end());
	if(num.size() < 4) return ans;
	set<vector<int> > vis;
	for(int i = 0; i < a.size()-3; i++)
	{
		if(i >= 1 && a[i] == a[i-1]) continue ;
		for(int j = i+1; j < a.size()-2; j++)
		{
			//if(j >= 2 && a[j] == a[j-1]) continue ; /*can't add this code, it will lose some status.*/
			int p1 = j+1, p2 = a.size()-1;
			while(p1 < p2)
			{
				int sum = a[i]+a[j]+a[p1]+a[p2];
				if(sum < target)
					p1++;
				else if(sum > target)
					p2--;
				else if(sum == target)
				{
					vector<int> cache;
					cache.push_back(a[i]), cache.push_back(a[j]);
					cache.push_back(a[p1]), cache.push_back(a[p2]);
					if(!vis.count(cache)) { ans.push_back(cache); vis.insert(cache); }
					p1++, p2--;
				}
			}
		}
	}
	return ans;
}

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        return process(num, target);
    }
};

//////////////
Solution g;

int main(void)
{
	vector<int> a;
	/*a.push_back(1); a.push_back(0); a.push_back(-1);
	a.push_back(0); a.push_back(2); a.push_back(-2);*/
	a.push_back(-1); a.push_back(0); a.push_back(1);
	a.push_back(2); a.push_back(-1); a.push_back(-4);
	vector<vector<int> > ans = g.fourSum(a, -1);
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
