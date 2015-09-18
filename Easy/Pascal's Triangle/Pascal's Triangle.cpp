#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int maxn = 50;
int table[maxn][maxn] = {0};

int cal(int i, int j)
{
	if(i == j || j == 1) return (table[i][j] = 1);
	if(table[i][j]) return table[i][j];
	else return ( table[i][j] = cal(i-1, j) + cal(i-1, j-1) );
}

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<vector<int> > ans;
        for(int i = 1; i <= numRows; i++)
        {
			vector<int> g;
			for(int j = 1; j <= i; j++)
			{
				g.push_back(cal(i, j));
			}
			ans.push_back(g);
		}
		return ans;
    }
};

//////////////
Solution g;

int main()
{
	vector<vector<int> > ans = g.generate(30);
	
	for(int i = 0; i < 30; i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	system("pause");
}
