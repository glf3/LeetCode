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

bool valid(const string &s, int i, int j)
{
	for(; i <= j; i++, j--)
		if(s[i] != s[j])
			return false;
	return true;
}

void dfs(const string &s, vector<vector<string> > &ans, int p, vector<string> a)
{
	if(p >= s.length()-1)
	{
		if(s.substr(p).size()) /* for string "bb",  if not add this code, it will add a empty string "" */
			a.push_back(s.substr(p));
		ans.push_back(a); 
		return ;
	}
	for(int i = p; i < s.length(); i++) if(valid(s, p, i))
	{
		a.push_back(s.substr(p, i-p+1));
		dfs(s, ans, i+1, a);
		a.pop_back();
	}
}

vector<vector<string> > process(const string &s)
{
	vector<vector<string> > ans;
	vector<string> a;
	dfs(s, ans, 0, a);
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
