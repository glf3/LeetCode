#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode Node;
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<Node*> q1;
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        q1.push(root);
        for(;;)
        {
			if(!q1.size()) break;
			queue<Node*> q2;
			vector<int> cache;
			while(!q1.empty())
			{
				Node* x = q1.front(); q1.pop();
				cache.push_back(x->val);
				if(x->left != NULL) q2.push(x->left);
				if(x->right != NULL) q2.push(x->right);
			}
			ans.push_back(cache);
			q1 = q2;
		}
		reverse(ans.begin(), ans.end());
		return ans;
    }
};

///////////////////
Solution g;

int main()
{
	Node *root1 = new Node(1);
	root1->left = new Node(2);
	root1->left->left = new Node(3);
	root1->left->right = new Node(4);
	
	root1->right = new Node(2);
	root1->right->left = new Node(4);
	root1->right->right = new Node(3);
	
	Node *root2 = new Node(1);
	root2->left = new Node(2);
	root2->left->right = new Node(3);
	
	root2->right = new Node(2);
	root2->right->right = new Node(3);
	
	vector<vector<int> > ans;
	ans = g.levelOrder(root1);
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	
	system("pause");
	return 0;
}
