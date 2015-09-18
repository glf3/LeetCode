#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
using namespace std;

void process(string &s)
{
	string t = "";
	for(int i = 0; i < s.length(); i++)
		if(s[i] != ' ')
			t += s[i];
	s = t;
}

int sum(string s)
{
	stack<int> A;
	stack<char> B;
	process(s);
	int n = s.length();
	int i = 0;
	while(i < n)
	{
		if(isdigit(s[i]))
		{
			int t = 0;
			while(isdigit(s[i]) && i < n)
				{ t = t*10+s[i]-'0'; i++; }
			A.push(t);
		}
		else if(s[i] == '+' || s[i] == '-' || s[i] == '(' || s[i] == ')')
		{
			if(s[i] == '(')
			{
				B.push(s[i]);
				i++;
			}
			else if(s[i] == ')')
			{
				int x = 0, y = 0;
				if(!A.empty()) { x = A.top(); A.pop(); }
				if(!A.empty() && B.top() != '(') { y = A.top(); A.pop(); }
				
				if(B.top() == '+')
					A.push(x+y);
				else if(B.top() == '-')
					A.push(y-x);
				else if(B.top() == '(')
					 { A.push(x); }
				if(!B.empty() && B.top() == '+' || B.top() == '-')
					B.pop();
				if(!B.empty()) B.pop();
				i++;
			}
			else if(s[i] == '+' || s[i] == '-')
			{
				if(B.empty() || B.top() == '(')
					 B.push(s[i]);
				else
				{
					int x = 0, y = 0;
					if(!A.empty()) { x = A.top(); A.pop(); }
					if(!A.empty()) { y = A.top(); A.pop(); }
					
					if(!B.empty() && B.top() == '+')
						A.push(x+y);
					else if(!B.empty() && B.top() == '-')
						A.push(y-x);
					B.pop();
					B.push(s[i]);
				}
				i++;
			}
		}
	}
	while(!B.empty())
	{
		int x = 0, y = 0;
		if(!A.empty())
			{ x = A.top(); A.pop(); }
		if(!A.empty())
			{ y = A.top(); A.pop(); }
		if(B.top() == '+')
			A.push(x+y);
		else if(B.top() == '-')
			A.push(y-x);
		B.pop();
	}
	return A.top();
}

class Solution {
public:
    int calculate(string s) {
        return sum(s);
    }
};

//////////////////
Solution g;

int main(void)
{
	printf("%d\n", g.calculate("(7)-(0)"));
	system("pause");
	return 0;
}
