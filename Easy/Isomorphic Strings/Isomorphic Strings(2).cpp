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

bool ok(string s, string t)
{
	map<char, char> mp;
	int n = s.length();
	if(!n) return true;
	for(int i = 0; i < n; i++)
	{
		if(!mp.count(s[i]))
			mp[s[i]] = t[i];
		else if(mp[s[i]] != t[i])
				return false;
	}
	return true;	
}

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		return ok(s, t) && ok(t, s);
    }
};

/////////////////////
Solution g;

int main(void)
{
	if(g.isIsomorphic("ab", "aa"))
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
	return 0;
}
