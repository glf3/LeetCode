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
using namespace std;

const int maxn = 110;
int d[maxn][maxn];
int n, m;

int dp(vector<vector<int> > &b)
{
	if(b[0][0] == 1)
		return 0;
	d[n-1][m-1] = 1;
	bool flag = 0;
	for(int i = m-1; i >= 0; i--)
	{
		if(flag) { d[n-1][i] = 0; continue; }
		if(b[n-1][i] == 1)
		{
			flag = 1;
			d[n-1][i] = 0;
		}
		else d[n-1][i] = 1;
	}
	flag = 0;
	for(int i = n-1; i >= 0; i--)
	{
		if(flag) { d[i][m-1] = 0; continue; }
		if(b[i][m-1] == 1)
		{
			flag = 1;
			d[i][m-1] = 0;
		}
		else d[i][m-1] = 1;
	}
	
	for(int i = n-2; i >= 0; i--)
	for(int j = m-2; j >= 0; j--)
	{
		if(!b[i][j+1])
			d[i][j] += d[i][j+1];
		if(!b[i+1][j])
			d[i][j] += d[i+1][j];
	}
	return d[0][0];
}

int cal(const vector<vector<int> > &a)
{
	memset(d, 0, sizeof(d));
	n = a.size(), m = a[0].size();
	vector<vector<int> > b = a;
	return dp(b);
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        return cal(obstacleGrid);
    }
};

////////////////
Solution g;

int main()
{
	vector<vector<int> > grid;
	vector<int> a, b, c;
	a.push_back(0), a.push_back(0), a.push_back(0);
	b.push_back(0), b.push_back(1), b.push_back(0);
	c.push_back(0), c.push_back(0), c.push_back(0);
	grid.push_back(a), grid.push_back(b), grid.push_back(c);
	printf("%d\n", g.uniquePathsWithObstacles(grid));
	system("pause");
}
