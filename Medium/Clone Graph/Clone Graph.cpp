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

struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};

typedef UndirectedGraphNode Node;
const int maxn = 1010;
bool vis[maxn];
map<int, Node*> cache;

Node* dfs(Node *x)
{
	Node *newNode = new Node(x->label);
	if(cache.count(x->label))
		return cache[x->label];
	cache[x->label] = newNode;
	int sz = x->neighbors.size();
	for(int i = 0; i < sz; i++)
	{
		Node *neighbors = dfs(x->neighbors[i]);
		newNode->neighbors.push_back(neighbors);
	}
	return newNode;
}

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node == NULL)
			return NULL;
		cache.clear();
		memset(vis, 0, sizeof(vis));
		Node *newNode = dfs(node);
    }
};

////////////////
Solution g;

void print(Node *a)
{
	printf("%d ", a->label);
	int sz = a->neighbors.size();
	for(int i = 0; i < sz; i++)
	{
		if(!vis[a->neighbors[i]->label])
		{
			vis[a->neighbors[i]->label] = 1;
			print(a->neighbors[i]);
		}
	}
}

int main()
{
	Node *a = new Node(0), *b = new Node(1), *c = new Node(2);
	a->neighbors.push_back(b), a->neighbors.push_back(c);
	b->neighbors.push_back(c), b->neighbors.push_back(a);
	c->neighbors.push_back(c), c->neighbors.push_back(b), c->neighbors.push_back(a);
	Node *newNode = g.cloneGraph(a);
	print(a);
	system("pause");
	return 0;
}
