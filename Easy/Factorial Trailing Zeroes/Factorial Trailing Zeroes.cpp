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

/*
* [n/k] equal to numbers in range[1,n] can divide exactly by k.
*/
class Solution {
public:
    int trailingZeroes(int n) {
		int ans = 0;
		while(n)
		{
			ans += n/5;
			n /= 5;
			/*
			*  calculate counts of: 5^1,5^2,5^3,5^4....
			*/
		}
		return ans;
    }
};

//////////////////
Solution g;

int main()
{
	printf("%d\n", g.trailingZeroes(15));
	system("pause");
}
