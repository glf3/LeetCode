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
	if(i == j || j == 0) return (table[i][j] = 1);
	if(table[i][j]) return table[i][j];
	else return ( table[i][j] = cal(i-1, j) + cal(i-1, j-1) );
}

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> ans;
    	for(int i = 0; i <= rowIndex; i++)
    		ans.push_back(cal(rowIndex, i));
    	return ans;
    }
};

//////////////
Solution g;

int main()
{
	vector<int> ans = g.getRow(0);
	
	for(int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	system("pause");
}
