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

int n, m;
typedef pair<int, int> PII;
vector<PII> b;

void Set(int x, int y, vector<vector<int> > &matrix)
{
	for(int i = 0; i < m; i++)
		matrix[x][i] = 0;
	for(int i = 0; i < n; i++)
		matrix[i][y] = 0;
}

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
		if(matrix.size() == 0)
			return ;
		b.clear();
		n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        	if(!matrix[i][j])
        	 b.push_back(make_pair(i, j));
        for(int i = 0; i < b.size(); i++)
        {
			Set(b[i].first, b[i].second, matrix);
		}
    }
};

//////////////
Solution g;

void print(const vector<vector<int> > ma)
{
	for(int i = 0; i < ma.size(); i++)
	{
		for(int j = 0; j < ma[i].size(); j++)
			printf("%d ", ma[i][j]);
		printf("\n");
	}
}

int main()
{
	vector<vector<int> > ma;
	vector<int> a, b, c;
	a.push_back(1), a.push_back(1), a.push_back(1);
	b.push_back(1), b.push_back(0), b.push_back(1);
	c.push_back(1), c.push_back(1), c.push_back(1);
	ma.push_back(a), ma.push_back(b), ma.push_back(c);
	g.setZeroes(ma);
	print(ma);
	system("pause");
}
