#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
using namespace std;

const int maxn = 510;
int table[maxn][maxn];

int dp(int i, int j, int n, vector<vector<int> > &triangle)
{
	if(i == n-1) return (table[i][j] = triangle[i][j]);
	if(table[i][j]) return table[i][j];
	return (table[i][j] = min(dp(i+1, j, n, triangle), dp(i+1, j+1, n, triangle)) + triangle[i][j]);
}

int cal(vector<vector<int> > &triangle)
{
	int n = triangle.size();
	return dp(0, 0, n, triangle);
}

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		memset(table, 0, sizeof(table));
        return cal(triangle);
    }
};

/////////////
Solution g;

int main()
{
	vector<int> a, b, c, d;
	a.push_back(2);
	b.push_back(3), b.push_back(4);
	c.push_back(6), c.push_back(5), c.push_back(7);
	d.push_back(4), d.push_back(1), d.push_back(8), d.push_back(3);;
	
	vector<vector<int> > res;
	res.push_back(a); res.push_back(b); res.push_back(c); res.push_back(d);
	printf("%d\n", g.minimumTotal(res));
	system("pause");
	return 0;
}
