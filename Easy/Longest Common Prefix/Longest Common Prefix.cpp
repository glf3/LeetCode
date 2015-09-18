#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
using namespace std;

string process(string s, string t)
{
	int n = s.length(), m = t.length();
	int res = 0;
	for(int i = 0; i < min(n, m); i++)
		if(s[i] == t[i]) res++;
		else break;
	return s.substr(0, res);
}

string work(vector<string> rhs)
{
	int sz = rhs.size();
	if(sz == 0) return "";
	if(sz == 1) return rhs[0];
	string s = rhs[0];
	int ans = 0;
	for(int i = 1; i < sz; i++) 
		s = process(s, rhs[i]);
	return s;
}

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        return work(strs);
    }
};

//////////////
Solution g;

int main()
{
	vector<string> strs;
	strs.push_back("caa"), strs.push_back("a");
	strs.push_back("acb");
	cout << g.longestCommonPrefix(strs) << endl;
	system("pause");
	return 0;
}
