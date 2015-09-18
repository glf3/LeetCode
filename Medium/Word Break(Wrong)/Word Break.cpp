#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

bool can(string s, unordered_set<string>  &dict)
{
	int n = s.length();
	if(dict.count(s)) return true;
	for(int i = 1; i < n; i++)
	{
		string s1 = s.substr(0, i), s2 = s.substr(i);
		//cout << s1 << " " << s2 << endl;
		if(dict.count(s1) && dict.count(s2))
			return true;
		if(dict.cound(s1) || dict.count(s2))
	}
	return false;
}

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>  &dict) {
        return can(s, dict);
    }
};

//////////////
Solution g;

int main()
{
	string s = "ab";
	unordered_set<string>  dict;
	dict.insert("a"), dict.insert("b");
	g.wordBreak(s, dict);
	system("pause");
	return 0;
}
