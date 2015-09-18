#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
using namespace std;

void work(string &s)
{
	s += '#';
	int n = s.length();
	string t = "";
	for(int i = 0, cnt = 1; i < n-1; i++)
	{
		if(s[i] == s[i+1])
			++cnt;
		else if(s[i] != s[i+1])
		{
			t += (cnt+'0'), t += s[i];
			cnt = 1;
		}
	}
	s = t;
}

string process(int n)
{
	string s = "1";
	for(int i = 2; i <= n; i++)
		work(s);
	return s;
}

class Solution {
public:
    string countAndSay(int n) {
        return process(n);
    }
};

//////////
Solution g;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		cout << g.countAndSay(n) << endl;
	}
	return 0;
}
