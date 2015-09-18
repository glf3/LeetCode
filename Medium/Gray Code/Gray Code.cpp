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
using namespace std;

const int maxn = 3;
typedef bitset<maxn> Bitset;

void Set(Bitset &b, int n)
{
	for(int i = 0; n != 0; i++, n >>= 1)
		if(n & 1)
			b.set(i);
}

/*
ith gray code = (ith Binary code >> 1) ^ i
*/
class Solution {
public:
    vector<Bitset> grayCode(int n) {
		vector<Bitset> ans;
        for(int i = 0; i < (1<<n); i++)
        {
			Bitset a, b;
			Set(b, i);
			a = b >> 1;
        	ans.push_back(a ^ b);
		}
		return ans;
    }
};

///////////
Solution g;

int main()
{
	vector<Bitset> ans = g.grayCode(3);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	system("pause");
}
