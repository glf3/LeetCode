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

class Solution {
public:
    int hammingWeight(uint32_t n) {
		int ans = 0;
        while(n)
        {
			n &= (n-1);
			ans++;
		}
		return ans;
    }
};

/////////////
Solution g;

int main(void)
{
	printf("%d\n", g.hammingWeight(11));
	system("pause");
}
