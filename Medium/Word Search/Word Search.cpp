#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int maxn = 510;
string s;
vector<vector<char> > b;
int n, m;
bool vis[maxn][maxn] = {0};

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int check(int x, int y, char c)
{
	if(x >= 0 && x < n && y >= 0 && y < m && b[x][y] == c && !vis[x][y])
		return true;
	return false;
}

void dfs(int x, int y, int cur, int &ans)
{
	if(ans) return ;
	if(cur >= s.length())
		{ ans = 1;  return ; }
	for(int i = 0; i < 4; i++)
	{
		int newx = x+dx[i], newy = y+dy[i];
		if(!check(newx, newy, s[cur])) continue ;
		vis[newx][newy] = 1;
		dfs(newx, newy, cur+1, ans);
		vis[newx][newy] = 0;
	}
	return ;
}

bool process(vector<vector<char> > &board, string word)
{
	b = board, s = word;
	int ans = 0;
	n = b.size(), m = b[0].size();
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	{
		if(b[i][j] == s[0])
		{
			memset(vis, 0, sizeof(vis));
			vis[i][j] = true;
			dfs(i, j, 1, ans);
		}
		if(ans) return true;
	}
	return false;
}

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        return process(board, word);
    }
};

///////////
Solution g;

int main()
{
	vector<vector<char> > a;
	a.push_back("ABCE"); a.push_back("SFCS");a.push_back("ADEE");
	string s;
	while(cin >> s)
	{
		if(g.exist(a, s))
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
