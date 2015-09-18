#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <cstdio>
using namespace std;

/*Sample Input
 005047e+6
.e1
46.e3
 +0e-
6+1
+-.
+.8
.
.1
 
-1.
e9
3.
3-2
3+2
--e

Sample Output
Case #1: Yes
Case #2: No
Case #3: Yes
Case #4: No
Case #5: No
Case #6: No
Case #7: Yes
Case #8: No
Case #9: Yes
Case #10: No
Case #11: Yes
Case #12: No
Case #13: Yes
Case #14: No
Case #15: No
Case #16: No
*/

void process(string &t) //delete prefix ' ' and postfix ' '
{
	int i, j;
	for(i = 0; t[i] == ' '; i++) ;
	for(j = t.length()-1; t[j] == ' '; j--) ;
	t = t.substr(i, j-i+1);
}

bool No_number(string s) // if string don't have number..
{
	for(int i = 0; i < s.length(); i++)
		if(isdigit(s[i]))
			return false;
	return true;
}

bool Count(string s, int flag) //check the string is valid or not
{
	if(No_number(s)) return 0;
	int dot = 0, cha = 0, neg = 0, pos = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(isalpha(s[i]))
		{
			if(s[i] == 'e')
				cha++;
			else return 0;
		}
		else if(isdigit(s[i])) ;
		else if(s[i] == '.') dot++;
		else if(s[i] == '-') neg++;
		else if(s[i] == '+') pos++;
		else return 0;
	}
	if(dot > 1) return 0;
	if(!flag)
		if((cha == 0 && neg == 1) || neg > 1) return 0;
	if(flag)
		if((cha == 0 && neg == 2) || neg > 2) return 0;
	if(!flag)
		if((cha == 0 && pos == 1) || pos > 1) return 0;
	if(flag)
		if((cha == 0 && neg == 2) || pos > 2) return 0;
	if(cha > 1) return 0;
	return 1;
}

int idx(string t) //find the postion of 'e'
{
	for(int i = 0; i < t.length(); i++)
		if(t[i] == 'e')
			return i;
	return -1;
}

bool ok(const char *s)
{
	string t = s;
	process(t); int n = t.length();
	if(!n) return 0;
	if(t[0] == '-' || t[0] == '+') // if(t[0] == '-' || t[0] == '+')
	{
		if(!Count(t, 1)) return 0;
		int p = idx(t);
		if(p >= 0) //include 'e'
		{
			if(p == 1) return 0;
			string a = t.substr(p), b = "";
			for(int i = 0; i < p; i++) b += t[i];
			int lena = a.length(), lenb = b.length();

			if(lena == 1) return 0;
			if(lenb == 1) return 0;
			
			if((lenb == 1 && b[lenb-1] == '.') || b[lenb-1] == '-') return 0;
			if((lenb == 1 && b[lenb-1] == '.') || b[lenb-1] == '+') return 0;
			
			int exP = 0, exN = 0;
			for(int i = 0; i < lena; i++)
				if(a[i] == '-')
					exN = 1;
				else if(a[i] == '+')
					exP = 1;
				else if(a[i] == '.')
					return 0;
			if(exN) //exist '-'
			{
				if(a[lena-1] == '-' || t[p+1] != '-')
					return 0;
			}
			if(exP) //exist '+'
			{
				if(a[lena-1] == '+' || t[p+1] != '+')
					return 0;
			}
		}
		else // not include 'e'
		{
			if(n == 2 && t[1] == '.')
				return 0;
		}
		return 1;
	}
	else // if(t[0] != '-' && t[0] != '+')
	{
		if(!Count(t, 0)) return 0;
		int p = idx(t);
		if(p >= 0) //include 'e'
		{
			if(p == 0) return 0;
			string a = t.substr(p), b = "";
			for(int i = 0; i < p; i++) b += t[i];
			int lena = a.length(), lenb = b.length();

			if(lena == 1) return 0;
			if(lenb == 0) return 0;
			
			if((lenb == 1 && b[lenb-1] == '.') || b[lenb-1] == '-') return 0;
			if((lenb == 1 && b[lenb-1] == '.') || b[lenb-1] == '+') return 0;
			
			int exP = 0, exN = 0;
			for(int i = 0; i < lena; i++)
				if(a[i] == '-')
					exN = 1;
				else if(a[i] == '+')
					exP = 1;
				else if(a[i] == '.')
					return 0;
			if(exN) // exist '-'
			{
				if(a[lena-1] == '-' || t[p+1] != '-')
					return 0;
			}
			if(exP) // exist '+'
			{
				if(a[lena-1] == '+' || t[p+1] != '+')
					return 0;
			}
		}
		else // not include 'e'
		{
			if(n == 1 && t[0] == '.')
				return 0;
		}
		return 1;
	}
}

class Solution {
public:
    bool isNumber(const char *s) {
        if(ok(s)) return 1;
        else return 0;
    }
};

//////////////
Solution g;

int main()
{
	char s[110];
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kase = 0;
	while(gets(s))
	{
		printf("Case #%d: ", ++kase);
		if(g.isNumber(s))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
