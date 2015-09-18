#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

bool process(string s)
{
    stack<char> S;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
		if(s[i] == '[' || s[i] == '{' || s[i] == '(')
			S.push(s[i]);
		else if(s[i] == ']')
		{
			if(S.size() != 0 && S.top() == '[') S.pop();
			else return false;
		}
		else if(s[i] == '}')
		{
			if(S.size() != 0 && S.top() == '{') S.pop();
			else return false;
		}
		else if(s[i] == ')')
		{
			if(S.size() != 0 && S.top() == '(') S.pop();
			else return false;	
		}
	}
	if(S.size() == 0) return true;
	else return false;
}

class Solution {
public:
    bool isValid(string s) {
		return process(s);
    }
};

////////////

Solution g;

int main()
{
	string s;
	while(cin >> s)
	{
		if(g.isValid(s))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
