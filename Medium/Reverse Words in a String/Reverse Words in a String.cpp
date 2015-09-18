#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
using namespace std;

void process(string &s)
{
	int i, j;
	int n = s.length();
	for(i = 0; s[i] == ' '; i++) ;
	for(j = n-1; s[j] == ' '; j--) ;
	s = s.substr(i, j-i+1);
}

class Solution {
public:
    void reverseWords(string &s) {
        process(s);
        if(!s.length()) { s = ""; return ; }
        stringstream ss(s);
        vector<string> cache; string t;
        while(ss >> t)
        	cache.push_back(t);
        s = "";
        s += cache[cache.size()-1];
        for(int i = cache.size()-2; i >= 0; i--)
        	s += (" " + cache[i]);
    }
};

////////////////
Solution g;
int main()
{
	string s;
	while(getline(cin, s))
	{
		g.reverseWords(s);
		cout << s << endl;
	}
	return 0;
}
