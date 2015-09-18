#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
using namespace std;

int N, K;
void dfs(int cur, vector<int> a, vector<vector<int> > &b)
{
	if(a.size() > K) return ;
	if(a.size() == K)
	{
		 	b.push_back(a);
		return ;
	}
	else for(int i = cur+1; i <= N; i++)
	{
		a.push_back(i);
		dfs(i, a, b);
		a.pop_back();
	}
	return ;
}

void process(int n, int k, vector<vector<int> > &ans)
{
	vector<int> a;
	N = n; K = k;
	
	dfs(0, a, ans);
	/*printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
		{
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}*/
}

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > ans;
        process(n, k, ans);
        return ans;
    }
};

//////////////////
Solution g;


int main(void)
{
	g.combine(4, 2);
	system("pause");
	return 0;
}
