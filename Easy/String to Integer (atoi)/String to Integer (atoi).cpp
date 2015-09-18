#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <cstdio>
using namespace std;

typedef long long LL;
const LL MAX_ = 2147483647LL;
const LL MIN_ = 2147483648LL;

bool no_number(string s)
{
	for(int i = 0; i < s.length(); i++)
		if(isdigit(s[i])) return false;
	return true;
}

bool process(const char *str, string &s)
{
	s = str;
	int n = strlen(str);
	if(!n) return false;
	int i;
	for(i = 0; s[i] == ' '; i++) ;
	s = s.substr(i);
	if(!s.length()) return false;
	if(s.length() == 1 && (s[0] == '-' || s[0] == '+')) return false;
	if(no_number(s)) return false;
	return true;
}

int idx(string s, int flag)
{
	int i;
	if(flag)
		i = 1;
	else
		i = 0;
	for(; ; i++)
		if(!isdigit(s[i]))
			return i;
}

int valid(const char *str)
{
	string s;
	if(!process(str, s)) return 0;
	
	if(s[0] == '-' || s[0] == '+')
	{
		int neg = 0, pos = 0;
		if(s[0] == '-') neg = 1;
		if(s[0] == '+') pos = 1;
		
		int p = idx(s, 1);
		string t = s.substr(1, p-1);
		if(!t.length()) return 0;
		LL x = 0;
		for(int i = 0; i < t.length(); i++)
		{
			x = x*10+t[i]-'0';
			if(pos)
			{
				if(x > MAX_)
					 return MAX_;
			}
			else if(neg)
			{
				if(x > MIN_)
					return MIN_;
			}
		}
		if(neg) x = -x;
		return x;
	}
	else
	{
		int p = idx(s, 0);
		string t = s.substr(0, p);
		if(!t.length()) return 0;
		LL x = 0;
		for(int i = 0; i < t.length(); i++)
		{
			x = x*10+t[i]-'0';
			if(x > MAX_)
				return MAX_;
		}
		return x;
	}
}

class Solution {
public:
    int atoi(const char *str) {
        return (int)valid(str);
    }
};

/////////////
Solution g;

int main()
{
	char str[110];
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kase = 0;
	while(gets(str))
	{
		printf("Case #%d: %d\n", ++kase, g.atoi(str));
	}
	return 0;
}
