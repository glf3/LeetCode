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

vector<vector<int> > work(vector<int> &num)
{
	int sz = num.size();
	sort(num.begin(), num.end());
	vector<vector<int> > ans;
	for(int i = 0; i < sz; i++)
	{
		if(i >= 1 && num[i] == num[i-1])
			continue ;
		int p1 = i+1, p2 = sz-1;
		while(p1 < p2)
		{
			if(p2 < sz-1 && num[p2] == num[p2+1])
				 { p2--; continue; }
			int target = num[i]+num[p1]+num[p2];
			if(target < 0)
				p1++;
			else if(target > 0)
				p2--;
			else if(target == 0)
			{
				vector<int> a;
				a.push_back(num[i]), a.push_back(num[p1]), a.push_back(num[p2]);
				ans.push_back(a);
				p1++; p2--;
			}
		}
	}
	return ans;
}

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        return work(num);
    }
};

/////////////
Solution g;

int main()
{
	vector<int> num;
	num.push_back(-1), num.push_back(0), num.push_back(1);
	num.push_back(2), num.push_back(-1), num.push_back(-4);
	vector<vector<int> > b = g.threeSum(num);
	for(int i =  0; i < b.size(); i++)
	{
		for(int j = 0; j < b[i].size(); j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
	system("pause");
}
