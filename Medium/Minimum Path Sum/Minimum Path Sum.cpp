#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n, m;
const int maxn = 510;
int table[maxn][maxn];

int dp(int i, int j, vector<vector<int> > &grid)
{
	int &ans = table[i][j];
	if(i == n-1 && j == m-1)
		return ( ans = grid[i][j] );
	if(ans) return ans;
	if(i == n-1)
		ans = dp(i, j+1, grid);
	else if(j == m-1)
		ans = dp(i+1, j, grid);
	else
		ans = min(dp(i, j+1, grid), dp(i+1, j, grid));
	ans += grid[i][j];
	return ans;
}

int cal(vector<vector<int> > &grid)
{
	n = grid.size(), m = grid[0].size();
	return dp(0, 0, grid);
}

class Solution {
public:
	Solution()
	{
		memset(table, 0, sizeof(table));
	}
    int minPathSum(vector<vector<int> > &grid) {
		return cal(grid);
    }
};

/////////////
Solution g;

int main()
{
	vector<int> a, b, c, d;
	a.push_back(2), a.push_back(2);
	b.push_back(3), b.push_back(4);
	c.push_back(6), c.push_back(5);
	d.push_back(4), d.push_back(1);
	
	vector<vector<int> > res;
	res.push_back(a); res.push_back(b); res.push_back(c); res.push_back(d);
	printf("%d\n", g.minPathSum(res));
	system("pause");
	return 0;	
}
