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

string process(string s)
{
	int len = s.length(), maxval = 0;
	int p1, p2;
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; i-j >= 0 && i+j < len; j++)
		{
			if(s[i-j] != s[i+j]) break ;
			if(j*2+1 > maxval) { maxval = j*2+1; p1 = i-j, p2 = i+j; }
		}
		for(int j = 0; i-j >= 0 && i+j+1 < len; j++)
		{
			if(s[i-j] != s[i+j+1]) break;
			if(j*2+2 > maxval) { maxval = j*2+2; p1 = i-j, p2 = i+j+1; }
		}
	}
	return s.substr(p1, p2-p1+1);
}

class Solution {
public:
    string longestPalindrome(string s) {
        return process(s);
    }
};

///////////////////
Solution g;

int main(void)
{
	cout << g.longestPalindrome("abcdcbabcee") << endl;
	system("pause");
	return 0;
}
