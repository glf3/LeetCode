#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
using namespace std;

typedef long long LL;
const LL INF = 0x3f3f3f3f;
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        LL x = 1, y = 1LL*n;
        LL ans = INF;
        while(x <= y)
        {
			LL mid = x+(y-x)/2;
			if(isBadVersion(mid))
			{
				y = mid-1;
				ans = mid;
			}
			else
				x = mid+1;
		}
		return ans;
    }
};

int main(void)
{
	return 0;
}
