#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int, int> PII;

string change(int n)
{
	stringstream ss;
	string s;
	ss << n;
	ss >> s;
	return s;
}

vector<string> process(vector<int> &nums)
{
	vector<string> ans;
	if(nums.size() == 0)
		return ans;
	vector<int> &a = nums;
	vector<PII> b;
	
	int n = a.size();
	a.push_back(INF);
	int p1 = 0;
	int begin = 0, end = 0;
	for(p1; p1 < n; )
	{
		while(a[p1] == a[p1+1]-1)
		{
			p1++;
			end++;
		}
		p1++;
		b.push_back(make_pair(begin, end));
		begin = end = p1;
	}
	for(int i = 0; i < b.size(); i++)
	{
		if(b[i].first == b[i].second)
			ans.push_back(change(a[b[i].first]));
		else
		{
			string t = change(a[b[i].first]) + "->" + change(a[b[i].second]);
			ans.push_back(t);
		}
	}
	/*for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;*/
	return ans;
}

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        return process(nums);
    }
};

//////////////////////////
Solution g;

int main(void)
{
	vector<int> a;
	a.push_back(0); a.push_back(1); a.push_back(2);
	a.push_back(4); a.push_back(5); a.push_back(7);
	g.summaryRanges(a);
	system("pause");
	return 0;
}
