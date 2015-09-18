#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
using namespace std;

int cal(string s)
{
	if(s[0] == '-')
	{
		int x = 0;
		for(int i = 1; i < s.length(); i++)
			x = x*10 + s[i]-'0';
		return -1*x;
	}
	else
	{
		int x = 0;
		for(int i = 0; i < s.length(); i++)
			x = x*10+s[i]-'0';
		return x;
	}
}

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int n = tokens.size();
        if(!n) return 0;
        for(int i = 0; i < n; i++)
        {
			if(isdigit(tokens[i][0]) || (tokens[i][0] == '-' && tokens[i] != "-"))
				 { int x = cal(tokens[i]); I.push(x); }
			else
			{
				string s = tokens[i];
				int x, y;
				if(!I.empty())
					 { y = I.top(); I.pop(); }
				if(!I.empty())
					 { x = I.top(); I.pop(); }
				switch(s[0])
				{
					case '+':
						I.push(x+y); break;
					case '-':
						I.push(x-y); break;
					case '*':
						I.push(x*y); break;
					case '/':
						I.push((x/y)); break;
					default:
						break;
				}
			}
		}
		if(!I.empty()) return I.top();
    }
private:
	stack<int> I;
};

/////////////////
Solution g;

int main()
{
	vector<string> t;
	t.push_back("3");
	t.push_back("-4");
	t.push_back("+");
	printf("%d\n", g.evalRPN(t));
	system("pause");
	return 0;
}
