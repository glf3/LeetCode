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

string change(const string &s)
{
	string t = s;
	sort(t.begin(), t.end());
	return t;
}

void print(const vector<vector<string> > &a)
{
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

vector<vector<string> > process(const vector<string> &a)
{
	int n = a.size();
	map<string, int> cache;
	int idx = 0;
	for(int i = 0; i < n; i++)
	{
		string s = change(a[i]);
		if(!cache.count(s))
			cache[s] = ++idx;
	}
	vector<vector<string> > ans(idx);
	vector<vector<string> > b(n+1);
	for(int i = 0; i < n; i++)
	{
		string s = change(a[i]);
		b[cache[s]].push_back(a[i]);
	}
	for(int i = 1; i <= cache.size(); i++)
		sort(b[i].begin(), b[i].end());
	for(int i = 1; i <= cache.size(); i++)
	for(int j = 0; j < b[i].size(); j++)
		ans[i-1].push_back(b[i][j]);
	//print(ans);
	return ans;
}

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
		vector<vector<string> > ans;
		if(strs.size() == 0) return ans;
        return process(strs);
    }
};

/////////////////////////
Solution g;

int main(void)
{
	vector<string> a;
	a.push_back("eat"); a.push_back("tea"); a.push_back("tan");
	a.push_back("ate"); a.push_back("nat"); a.push_back("bat");
	g.groupAnagrams(a);
	system("pause");
	return 0;
}
