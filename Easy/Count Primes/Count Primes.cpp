#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

const int maxn = 1000010;
bool vis[maxn];

class Solution {
public:
    int countPrimes(int n) {
		int ans = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 2; i*i <= n; i++) if(!vis[i])
		{
			for(int j = i*i; j <= n; j += i)
				vis[j] = 1;
		}
		for(int i = 2; i < n; i++)
			if(!vis[i])
				ans++;
		return ans;
    }
};

//////////////////////
Solution g;

int main(void)
{
	printf("%d\n", g.countPrimes(2));
	system("pause");
}
