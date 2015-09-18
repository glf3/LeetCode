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
using namespace std;

typedef pair<int, int> PII;
typedef multimap<int, PII> Map;

void print(vector<vector<int> > ans)
{
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
}

vector<vector<int> > Unique(vector<vector<int> > ans)
{
	vector<vector<int> > tmp;
	set<int> vis;
	for(int i = 0; i < ans.size(); i++)
		for(int j = i+1; j < ans.size(); j++)
		{
			if(ans[i][0] == ans[j][0] && ans[i][1] == ans[j][1] && ans[i][2] == ans[j][2])
				 { vis.insert(j); break; }
		}
	for(int i = 0; i < ans.size(); i++) if(!vis.count(i))
		tmp.push_back(ans[i]);
	return tmp;
}

vector<vector<int> > work(vector<int> &num)
{
	vector<vector<int> > ans;
	int n = num.size();
	if(n < 3) return ans;
	sort(num.begin(), num.end());
	Map p;
	for(int i = 0; i < n; i++)
	for(int j = i+1; j < n; j++)
	{
		int val = num[i]+num[j];
		PII pii = make_pair(i, j);
		p.insert(make_pair(val, pii));
	}
	
	for(int i = 0; i < n; i++)
	{
		if(p.count(-num[i]))
		{
			Map::iterator begin = p.lower_bound(-num[i]);
			Map::iterator end = p.upper_bound(-num[i]);
			while(begin != end)
			{
				PII pii = begin->second;
				int j = pii.first, k = pii.second;
				if(i != j && i != k)
				{
					vector<int> tmp;
					tmp.push_back(num[i]), tmp.push_back(num[j]), tmp.push_back(num[k]);
					sort(tmp.begin(), tmp.end());
					ans.push_back(tmp);
				}
				begin++;
			}
		}
	}
	ans = Unique(ans);
	return ans;
}

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        return work(num);
    }
};

///////////////////
Solution g;

int main()
{
	vector<int> num;
	num.push_back(-1), num.push_back(0), num.push_back(1);
	num.push_back(2), num.push_back(-1), num.push_back(-4);
	vector<vector<int> > ans = g.threeSum(num);
	print(ans);
	system("pause");
	return 0;
}
