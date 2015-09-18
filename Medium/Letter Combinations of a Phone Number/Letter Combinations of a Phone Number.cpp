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

typedef set<string>::iterator Iterator;

const int maxn = 20;
string digit[maxn] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

bool valid(char c) { return isdigit(c); }
int idx(char c) { return c-'0'; }

void dfs(int cur, string cache, const string &s, set<string> &vis)
{
	if(cur >= s.length())
	{
		if(cache.length() != 0) /* "" return [], not [""] */
			vis.insert(cache);
		return ;
	}
	if(valid(s[cur]))
	{
		bool flag = false;
		for(int i = 0; i < digit[idx(s[cur])].length(); i++)
		{
			flag = true;
			cache += digit[idx(s[cur])][i];
			dfs(cur+1, cache, s, vis);
			cache = cache.substr(0, cache.length()-1);
		}
		if(!flag) dfs(cur+1, cache, s, vis);
	}
	else dfs(cur+1, cache, s, vis);
}

vector<string> process(const string &s)
{
	vector<string> ans;
	set<string> vis;
	dfs(0, "", s, vis);
	if(vis.empty())	return ans;
	for(Iterator it = vis.begin(); it != vis.end(); it++)
		ans.push_back(*it);
	return ans;
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return process(digits);
    }
};

////////////////////
Solution g;

int main(void)
{
	string digits = "23";
	vector<string> a = g.letterCombinations(digits);
	for(int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
