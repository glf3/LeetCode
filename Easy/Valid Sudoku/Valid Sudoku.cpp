#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <cstdio>
using namespace std;

const int N = 9;
bool vis[10];

bool Row(vector<vector<char> > bd)
{
	for(int i = 0; i < N; i++)
	{
		memset(vis, 0, sizeof(vis));
		for(int j = 0; j < N; j++) if(isdigit(bd[i][j]))
		{
			char c = bd[i][j];
			if(vis[c-'0']) return false;
			vis[c-'0'] = true;;
		}
	}
	return true;
}

bool Column(vector<vector<char> > bd)
{
	for(int j = 0; j < N; j++)
	{
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < N; i++) if(isdigit(bd[i][j]))
		{
			char c = bd[i][j];
			if(vis[c-'0']) return false;
			vis[c-'0'] = true;
		}
	}
	return true;
}

bool Block(vector<vector<char> > bd)
{
	for(int i = 0; i < N; i += 3)
	{
		for(int j = 0; j < N; j += 3)
		{
			memset(vis, 0, sizeof(vis));
			for(int k = i; k < i+3 && i+3 <= N; k++)
			{
				for(int p = j; p < j+3 && j+3 <= N; p++) if(isdigit(bd[k][p]))
				{
					char c = bd[k][p];
					if(vis[c-'0']) return false;
					vis[c-'0'] = true;
				}
			}
		}
	}
	return true;
}

bool ok(vector<vector<char> > bd)
{
	int x = Row(bd), y = Column(bd), z = Block(bd);
	if(x && y && z) return true;
	else return false;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        return ok(board);
    }
};

///////////////////////
Solution g;

int main()
{
	vector<vector<char> > res;
	res.push_back("53..7....");
	res.push_back("6..195...");
	res.push_back(".98....6.");
	res.push_back("8...6...3");
	res.push_back("4..8.3..1");
	res.push_back("7...2...6");
	res.push_back(".6....28.");
	res.push_back("...419..5");
	res.push_back("....8..79");
	
	if(g.isValidSudoku(res))
		printf("Yes\n");
	else
		printf("No\n");
	system("pause");
}
