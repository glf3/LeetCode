#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
using namespace std;

bool allzero(vector<int> a)
{
	for(int i = 0; i < a.size(); i++)
		if(a[i] != 0) return false;
	return true;
}

class Solution {
public:
    string addBinary(string a, string b) {
		int n = a.length(), m = b.length();
		reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
		vector<int> c; c.resize(n+m+10);
		
		int i;
		for(i = 0; i < n; i++)
			c[i] += a[i]-'0';
		for(i = 0; i < m; i++)
			c[i] += b[i]-'0';
		if(allzero(c)) return "0";
		int d = 0;
		for(i = 0; i < max(n, m); i++)
		{
			int tmp = c[i]+d;
			c[i] = tmp%2;
			d = tmp / 2;
		}
		if(d) c[i] = d;
		
		string ans = "";
		for(; i >= 0; i--)
			if(c[i] != 0) break;
		for(; i >= 0; i--)
			ans += (c[i]+'0');
		return ans;
    }
};

////////////////
Solution g;

int main()
{
	cout << g.addBinary("11", "1") << endl;
	system("pause");
	return 0;
}
