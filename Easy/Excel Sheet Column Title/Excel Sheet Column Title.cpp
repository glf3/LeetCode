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

string reverse(string s)
{
	string t = "";
	for(int i = s.length()-1; i >= 0; i--)
		t += s[i];
	return t;
}

class Solution {
public:
    string convertToTitle(int n) {
		string s = "";
		while(n)
		{
			n--;
			s += (n%26+'A');
			n /= 26;
		}
		return reverse(s);
    }
};

////////////////

Solution g;

int main(void)
{
	cout << g.convertToTitle(26) << endl;
	system("pause");
}
