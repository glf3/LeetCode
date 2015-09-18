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

typedef map<char, int>::iterator Iterator;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
		map<char, int> a, b;
		for(int i = 0; i < s.length(); i++)
			a[s[i]]++;
		for(int i = 0; i < t.length(); i++)
			b[t[i]]++;
		int n = s.length();
		set<char> vis;
		for(int i = 0; i < n; i++)
		{
			if(s[i] != t[i])
			{
				if(vis.count(s[i]) || vis.count(t[i]))
					return false;
				if(a[s[i]] != b[t[i]])
					return false;
				else
					{ a[s[i]]--; b[t[i]]--; }
			}
			else if(s[i] == t[i])
				vis.insert(s[i]);
		}
		return true;
    }
};

/////////////////////
Solution g;

int main(void)
{
	if(g.isIsomorphic("gee", "add"))
		printf("yes\n");
	else
		printf("no\n");
	if(g.isIsomorphic("foo", "bar"))
		printf("yes\n");
	else
		printf("no\n");
	if(g.isIsomorphic("paper", "title"))
		printf("yes\n");
	else
		printf("no\n");
	if(g.isIsomorphic("aba", "baa"))
		printf("yes\n");
	else
		printf("no\n");
	if(g.isIsomorphic("aabbtt", "tbtbaa"))
		printf("yes\n");
	else
		printf("no\n");
	if(g.isIsomorphic("abba", "abab"))
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
	return 0;
}
