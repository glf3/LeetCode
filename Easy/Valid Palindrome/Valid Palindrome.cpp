#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

bool ok(string t)
{
    int n = t.length();
    for(int i = 0; i < n; i++)
            if(t[i] != t[n-i-1]) return false;
    return true;
}

class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(int i = 0; i < s.length(); i++)
        {
			if(isalpha(s[i])) t += tolower(s[i]);
			if(isdigit(s[i])) t += s[i];
		}
        return ok(t);
    }
};

///////////////////
Solution g;

int main()
{
	printf("%d\n", g.isPalindrome("aA"));
	system("pause");
}
