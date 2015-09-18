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

int BSearch(const vector<int> &a, const int target)
{
	int x = 0, y = a.size()-1;
	int ans = 0;
	while(x <= y)
	{
		int mid = x+(y-x)/2;
		if(a[mid] <= target)
		{
			ans = mid;
			x = mid+1;
		}
		else
			y = mid-1;
	}
	return ans;
}

bool exist(vector<vector<int> > &matrix, int target)
{
	int n = matrix.size(), m = matrix[0].size();
	vector<int> a, b;
	for(int i = 0; i < n; i++)
		a.push_back(matrix[i][0]);
	int p1 = BSearch(a, target);
	for(int i = 0; i < m; i++)
		b.push_back(matrix[p1][i]);
	int p2 = lower_bound(b.begin(), b.end(), target)-b.begin();
	if(p2 < b.size() && matrix[p1][p2] == target)
		return true;
	else
		return false;
}

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if(matrix.size() == 0)
			return false;
        return exist(matrix, target);
    }
};

///////////////////////
Solution g;

int main()
{
	vector<vector<int> > ma;
	vector<int> a, b, c;
	/*a.push_back(1), a.push_back(3), a.push_back(5), a.push_back(7);
	b.push_back(10), b.push_back(11), b.push_back(16), b.push_back(20);
	c.push_back(23), c.push_back(30), c.push_back(34), c.push_back(50);*/
	/*a.push_back(-10), a.push_back(-9);
	b.push_back(-6), b.push_back(-5);
	c.push_back(-3), c.push_back(-1);*/
	a.push_back(-8), a.push_back(-7);
	b.push_back(-5), b.push_back(-5);
	ma.push_back(a); //ma.push_back(b); ma.push_back(c);
	ma.push_back(b);
	g.searchMatrix(ma, 0);
	system("pause");
}
