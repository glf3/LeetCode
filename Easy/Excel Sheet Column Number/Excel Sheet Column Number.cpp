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

int pow1(int base, int n)
{
	int res = 1;
	for(int i = 0; i < n; i++)
		res *= base;
	return res;
}

class Solution {
public:
    int titleToNumber(string s) {
		int ans = 0;
        for(int i = s.length()-1, j = 0; i >= 0; i--, j++)
        	ans += (s[i]-'A'+1)*pow1(26, j);
        return ans;
    }
};

//////////////////
Solution g;

int main(void)
{
	printf("%d\n", g.titleToNumber("AB"));
	system("pause");
	return 0;
}
