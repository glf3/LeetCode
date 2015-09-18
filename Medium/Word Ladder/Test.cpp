#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

const int maxn = 1010;
const int maxm = 510*510;
const int INF = 0x3f3f3f3f;

int n;
int d[maxn];
int first[maxn];
int cnt;
int length;

struct Edge
{
	int u, v, w;
	int next;
}edge[maxm];

typedef pair<int, int> pii;

inline int Dijkstra(int s, int t)
{
	priority_queue<int, vector<pii>, greater<pii> > Q;
	for(int i = 0; i < n; i++) d[i] = (i == 0)? 0:INF;
	Q.push(make_pair(0, s));
	while(!Q.empty())
	{
		pii u = Q.top(); Q.pop();
		int x = u.second;
		if(u.first != d[x]) continue ;
		for(int e = first[x]; e != -1; e = edge[e].next)
		{
			int v = edge[e].v, w = edge[e].w;
			if(d[v] > d[x]+w)
			{
				d[v] = d[x]+w;
				Q.push(make_pair(d[v], v));
			}
		}
	}
	if(d[t] != INF)
		return d[t];
	else
		return 0;
}

inline bool canchange(string s, string t)
{
	int Cnt = 0;
	for(int i = 0; i < length; i++)
		if(s[i] != t[i])
			++Cnt;
	if(Cnt > 1) return false;
	return true;
}

typedef set<string> Set;
typedef map<string, int> Map;
Map cache;

inline void init()
{
	cnt = 0;
	memset(first, -1, sizeof(first));
	cache.clear();
}

inline void read_graph(int u, int v, int w)
{
	edge[cnt].v = v, edge[cnt].w = w;
	edge[cnt].next = first[u], first[u] = cnt++;
}

inline void build(string s, string t, set<string> &dict)
{
	init();
	Set::iterator it, it2, itTmp;
	n = 0;
	if(!cache[s])
		cache[s] = n++;
	for(it = dict.begin(); it != dict.end(); it++)
		if(!cache[*it])
			cache[*it] = n++;
	if(!cache[t])
		cache[t] = n++;
		
	for(it = dict.begin(); it != dict.end(); it++)
		if(canchange(s, *it))
		{
			int x = cache[s], y = cache[*it];
			read_graph(x, y, 1), read_graph(y, x, 1);
		}
		
	for(it = dict.begin(); it != dict.end(); it++)
		if(canchange(t, *it))
		{
			int x = cache[t], y = cache[*it];
			read_graph(x, y, 1), read_graph(y, x, 1);
		}
	
	for(it = dict.begin(); it != dict.end(); it++)
	{
		itTmp = it;
		for(it2 = ++itTmp; it2 != dict.end(); it2++)
			if(canchange(*it, *it2))
			{
				int x = cache[*it], y = cache[*it2];
				read_graph(x, y, 1), read_graph(y, x, 1);
			}
	}
}

inline int solve(string start, string end, set<string> &dict)
{
	if(start == end) return 0;
	length = start.length();
	build(start, end, dict);
	int s = cache[start], t = cache[end];
	return Dijkstra(s, t);
}

class Solution {
public:
    int ladderLength(string start, string end, set<string> &dict) {
        return solve(start, end, dict);
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
		printf("%d\n", ans+1);
	else
		printf("0\n");
	system("pause");
	return 0;
}
