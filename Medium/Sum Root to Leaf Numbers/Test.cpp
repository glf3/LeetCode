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

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode Node;
vector<string> ans;

struct node
{
	string s;
	Node *rt;
	node(string s="", Node *rt = NULL): s(s), rt(rt) {}
};

string IntergertoString(int x)
{
	stringstream ss;
	string s;
	ss << x;
	ss >> s;
	return s;
}

int StringtoInterger(string s)
{
	int i, x = 0;
	for(i = 0; s[i] == '0'; i++);
	for(; i < s.length(); i++)
		x = x*10+s[i]-'0';
	return x;
}

void bfs(Node *root)
{
	queue<node> Q;
	node cur, next;
	Q.push(node("", root));
	while(!Q.empty())
	{
		cur = Q.front(); Q.pop();
		string s = cur.s; Node *rt = cur.rt;
		if(rt->left == NULL && rt->right == NULL)
		{
			s += IntergertoString(rt->val);
			ans.push_back(s);
		}
		else
		{
			if(rt->left != NULL)
			{
				next = cur;
				next.s += IntergertoString(rt->val);
				next.rt = rt->left;
				Q.push(next);
			}
			else if(rt->right != NULL)
			{
				next = cur;
				next.s += IntergertoString(rt->val);
				next.rt = rt->right;
				Q.push(next);
			}
		}
	}
}

int calculate(Node *root)
{
	if(root == NULL)
		return 0;
	bfs(root);
	int res = 0;
	for(int i = 0; i < ans.size(); i++)
		res += StringtoInterger(ans[i]);
	return res
}

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return calculate(root);
    }
};

////////////////
Solution g;

int main()
{
	Node *root = new Node(1);
	root->right = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(5);
	root->left->right = new Node(10);
	printf("%d\n", g.sumNumbers(root));
	system("pause");
	return 0;
}
