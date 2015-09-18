#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		if(x < 0) return false;
        string s; stringstream ss;
        ss << x;
        ss >> s;
        int n = s.length();
        for(int i = 0; i < n; i++)
        	if(s[i] != s[n-i-1]) return false;
        return true;
    }
};

///////////////////
Solution g;

int main()
{
	int x = g.isPalindrome(122242341);
	printf("%d\n", x);
	system("pause");
}
