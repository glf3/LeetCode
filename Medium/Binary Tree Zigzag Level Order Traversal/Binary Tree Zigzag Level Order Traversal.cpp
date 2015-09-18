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

vector<vector<int> >process(Node *root)
{
	vector<vector<int> > ans;
	if(root == NULL)
		return ans;
	queue<Node*> q1;
	q1.push(root);
	for(;;)
	{
		if(q1.empty()) break;
		queue<Node *> q2;
		vector<int> a;
		while(!q1.empty())
		{
			Node *x = q1.front(); q1.pop();
			a.push_back(x->val);
			if(x->left != NULL)
				q2.push(x->left);
			if(x->right != NULL)
				q2.push(x->right);
		}
		ans.push_back(a);
		q1 = q2;
	}
	int sz = ans.size();
	for(int i = 1; i < sz; i += 2)
		reverse(ans[i].begin(), ans[i].end());
	/*for(int i = 0; i < ans.size(); i++)
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        return process(root);
    }
};

////////////////
Solution g;

int main()
{
	Node *root = new Node(3);
	root->left = new Node(9), root->right = new Node(20);
	root->right->left = new Node(15), root->right->right = new Node(7);
	vector<vector<int> > ans = g.zigzagLevelOrder(root);
	system("pause");
	return 0;
}
