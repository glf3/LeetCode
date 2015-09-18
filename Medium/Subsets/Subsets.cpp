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
#include <stack>
using namespace std;

void print(vector<vector<int> > &ans)
{
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
}

void subset(int n, int s, vector<vector<int> > &ans, vector<int> &S)
{
	vector<int> a;
	for(int i = 0; i < n; i++)
		if(s & (1<<i))
			a.push_back(S[i]);
	ans.push_back(a);
}

vector<vector<int> > process(vector<int> &S)
{
	int n = S.size();
	vector<vector<int> > ans;
	sort(S.begin(), S.end());
	for(int i = 0; i < (1<<n); i++)
		subset(n, i, ans, S);
	return ans;
}

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        return process(S);
    }
};

//////////////////////
Solution g;

int main(void)
{
	vector<int> S;
	S.push_back(1); S.push_back(2); S.push_back(3);
	g.subsets(S);
	system("pause");
	return 0;
}
