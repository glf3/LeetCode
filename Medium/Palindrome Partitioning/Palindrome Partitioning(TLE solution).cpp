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

bool valid(const string &s)
{
	for(int i = 0, j = s.length()-1; i <= j; i++, j--)
		if(s[i] != s[j])
			return false;
	return true;
}

void dfs(int count, int times, vector<int> p, const string &s, vector<vector<string> > &ans, int cur)
{
	if(p.size() == 1)
	{
		string t = s.substr(0, p[0]+1);
		if(!valid(t)) return ;
	}
	else if(p.size() > 1)
	{
		int size = p.size();
		string t = s.substr(p[size-2]+1, p[size-1]-p[size-2]);
		if(!valid(t)) return ;
	}
	if(count == times)
	{
		vector<string> a;
		string t;
		int first = 1, pre = 0;
		for(int i = 0; i < p.size(); i++)
		{
			if(first)
			{
				t = s.substr(pre, p[0]-pre+1);
				if(valid(t))
					a.push_back(t);
				else return ;
				first = 0;
				pre = p[0];
			}
			else
			{
				t = s.substr(pre+1, p[i]-p[i-1]);
				if(valid(t)) a.push_back(t);
				else return ;
				pre = p[i];
			}
		}
		t = s.substr(p[p.size()-1]+1);
		if(!valid(t)) return ;
		a.push_back(t);
		ans.push_back(a);
		return ;
	}
	for(int i = cur; i < s.length()-1; i++)
	{
		p.push_back(i);
		dfs(count+1, times, p, s, ans, i+1);
		p.pop_back();
	}
}

/*
* dfs(int count, int times, vector<int> p, const string &s, vector<vector<string> > &ans, int cur)
*/

vector<vector<string> > process(const string &s)
{
	vector<vector<string> > ans;
	vector<int> p;
	if(valid(s)) { vector<string> a; a.push_back(s); ans.push_back(a); }
	int n = s.length()-1;
	for(int i = 1; i <= n; i++)
	{
		p.clear();
		dfs(0, i, p, s, ans, 0);
	}
	return ans;
}

class Solution {
public:
    vector<vector<string> > partition(string s) {
        return process(s);
    }
};

/////////////////
Solution g;

int main(void)
{
	vector<vector<string> > a = g.partition("cabeeebac");
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < a[i].size(); j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
