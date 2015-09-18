#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

typedef map<char, int> Map;
Map table;

int calculate(string s)
{
	int n = s.length();
	int val = table[s[n-1]];
	for(int i = n-2; i >= 0; i--)
		if(table[s[i+1]] > table[s[i]])
			val -= table[s[i]];
		else
			val += table[s[i]];
	return val;
}

class Solution {
public:
	Solution()
	{
		table['I'] = 1;
		table['V'] = 5;
		table['X'] = 10;
		table['L'] = 50;
		table['C'] = 100;
		table['D'] = 500;
		table['M'] = 1000;
	}
    int romanToInt(string s) {
        return calculate(s);
    }
};

////////////
Solution g;

int main()
{
	string s;
	while(cin >> s)
	{
		int ans = g.romanToInt(s);
		printf("%d\n", ans);
	}
	return 0;
}
