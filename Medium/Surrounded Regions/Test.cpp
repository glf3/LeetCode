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

const int maxn = 500 + 10;
bool vis[maxn][maxn];
int n, m;

struct Node
{
	int x, y;
	Node(int x=0, int y=0):x(x), y(y) {}
};

bool check(int x, int y, vector<string> &board)
{
	if(x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O' && !vis[x][y])
		return true;
	return false;
}

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void bfs(int x, int y, vector<string> &board)
{
	queue<Node> Q;
	Q.push(Node(x, y));
	vis[x][y] = true;
	board[x][y] = '*';
	Node cur, next;
	while(!Q.empty())
	{
		cur = Q.front(); Q.pop();
		int x = cur.x, y = cur.y;
		for(int i = 0; i < 4; i++)
		{
			int newx = x+dx[i], newy = y+dy[i];
			if(!check(newx, newy, board)) continue;
			board[newx][newy] = '*';
			vis[newx][newy] = true;
			Q.push(Node(newx, newy));
		}
	}
}

void change(vector<string> &board)
{
	n = board.size();
	if(!n) return ;
	m = board[0].size();
	if(!m) return ;
	
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; i++)
		if(board[i][0] == 'O' && !vis[i][0])
			bfs(i, 0, board);
	for(int i = 0; i < n; i++)
		if(board[i][m-1] == 'O' && !vis[i][m-1])
			bfs(i, m-1, board);
	for(int i = 1; i < m-1; i++)
		if(board[0][i] == 'O' && !vis[0][i])
			bfs(0, i, board);
	for(int i = 1; i < m-1; i++)
		if(board[n-1][i] == 'O' && !vis[n-1][i])
			bfs(n-1, i, board);
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
		if(board[i][j] == '*')
			board[i][j] = 'O';
		else if(board[i][j] == 'O')
			board[i][j] = 'X';
	for(int i = 0; i < n; i++)
		cout << board[i] << endl;
}

class Solution {
public:
    void solve(vector<string> &board) {
        change(board);
    }
};

//////////////////
Solution g;

int main()
{
	vector<string> b;
	/*b.push_back("XOXOXO");
	b.push_back("OXOXOX");
	b.push_back("XOXOXO");
	b.push_back("OXOXOX");*/
	b.push_back("XOX");
	b.push_back("OXO");
	b.push_back("XOX");
	g.solve(b);
	system("pause");
	return 0;
}
