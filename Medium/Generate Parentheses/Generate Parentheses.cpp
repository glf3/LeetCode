#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

bool valid(const vector<int> &a, bool status)
{
	int n = a.size();
	int sz = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == 1)
			sz++;
		else if(a[i] == -1)
		{
			if(sz <= 0)
				return false;
			sz--;
		}
	}
	if(status)
		if(!sz)
			return true;
		else
			return false;
	if(!status)
		if(sz >= 0)
			return true;
		else
			return false;
}

string change(const vector<int> &a)
{
	int n = a.size();
	string str = "";
	for(int i = 0; i < n; i++)
		if(a[i] == 1)
			str += "(";
		else
			str += ")";
	return str;
}

void dfs(int n, int depth, vector<int> a, vector<string> &ans)
{
	if(!valid(a, 0)) return ;
	if(n == depth)
	{
		if(valid(a, 1))
			ans.push_back(change(a));
		return ;
	}
	a.push_back(1);
	dfs(n, depth+1, a, ans);
	a.pop_back();
	
	a.push_back(-1);
	dfs(n, depth+1, a, ans);
	a.pop_back();
	return ;
}

vector<string> process(int n)
{
	vector<string> ans;
	vector<int> a;
	if(!n) return ans;
	n *= 2;
	dfs(n, 0, a, ans);
	/*for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;*/
	return ans;
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return process(n);
    }
};

////////////////////////
Solution g;

int main(void)
{
	g.generateParenthesis(3);
	system("pause");
	return 0;
}
