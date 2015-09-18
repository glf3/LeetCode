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

int next(int p, string s)
{
	for(int i = p; i < s.length(); i++)
		if(s[i] == '.')
			return i;
	return -1;
}

void process(string &s)
{
	int i;
	int p = next(0, s);
	if(p != -1)
	{
		string tmp = "", t = s.substr(0, p);
		for(i = 0; t[i] == '0'; i++) ;
		if(i >= t.length())
		{
			tmp += s.substr(p-1);
		}
		else
			tmp += s.substr(i);
		s = tmp;
	}
	else
	{
		int i;
		for(i = 0; s[i] == '0'; i++) ;
		if(i < s.length())
			s = s.substr(i);
		else
			s = "0";
	}
}

class Solution {
public:
    int compareVersion(string version1, string version2) {
		string &v1 = version1, &v2 = version2;
		process(v1), process(v2); //È¥Ç°µ¼0
		int p1 = 0, p2 = 0;
		int len1 = v1.length(), len2 = v2.length();
		while(p1 < len1 || p2 < len2)
		{
			int s1 = 0;
			while(p1 < len1)
			{
				if(v1[p1] != '.')
					s1 = s1*10+(v1[p1]-'0');
				else
					 { p1++; break; }
				p1++;
			}
			int s2 = 0;
			while(p2 < len2)
			{
				if(v2[p2] != '.')
					s2 = s2*10+(v2[p2]-'0');
				else
					{ p2++; break; }
				p2++;
			}
			if(s1 > s2)
				return 1;
			if(s1 < s2)
				return -1;
		}
		return 0;
	}
};

/////////////////
Solution g;

int main(void)
{
	string s = "000000.123456";
	process(s);
	cout << s << endl;
	printf("%d\n", g.compareVersion("1", "1.0.0.1"));
	system("pause");
}
