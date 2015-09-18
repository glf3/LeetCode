#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

struct Node
{
	string s;
	int step;
	Node(string s="", int step=0):s(s), step(step) {}
};

typedef unordered_set<string> Set;

int bfs(string start, string end, unordered_set<string> &dict)
{
	dict.insert(start), dict.insert(end);
	if(start == end) return 0;
	queue<Node> Q;
	Node cur, next;
	Set vis; vis.insert(start);
	Q.push(Node(start, 0));
	int length = start.length();
	while(!Q.empty())
	{
		cur = Q.front(); Q.pop();
		if(cur.s == end) return cur.step;
		string s = cur.s;
		int step = cur.step;
		for(int i = 0; i < length; i++)
		{
			string tmp = s;
			for(char c = 'a'; c <= 'z'; c++)
			{
				tmp[i] = c;
				if(dict.count(tmp) && !vis.count(tmp))
					 { Q.push(Node(tmp, step+1)); vis.insert(tmp); }
			}
		}
	}
	return 0;
}

int solve(string s, string t, unordered_set<string> &dict)
{
	int ans = bfs(s, t, dict);
	return ans;
}

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
		int ans = solve(start, end, dict);
		if(ans)
			return ++ans;
		else
			return 0;
    }
};

//////////////////
Solution g;

int main()
{
	string s = "hit", t = "cog";
	Set S;
	S.insert("hot"); S.insert("dot"); S.insert("dog"); S.insert("lot"); S.insert("log");
	int ans = g.ladderLength(s, t, S);
	if(ans)
		printf("%d\n", ans);
	else
		printf("0\n");
	system("pause");
	return 0;
}
