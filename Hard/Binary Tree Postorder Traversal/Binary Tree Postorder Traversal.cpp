#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include <cstring> 
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode Node;

vector<int> postorder(Node *root)
{
	stack<Node*> S;
	vector<int> ans;
	S.push(root);
	Node *pre = NULL, *T;
	while(!S.empty())
	{
		T = S.top();
		if((T->left == NULL && T->right == NULL) || (pre != NULL && (T->left == pre || T->right == pre)))
		{
			ans.push_back(T->val); S.pop();
			pre = T;
		}
		else
		{
			if(T->right != NULL) S.push(T->right);
			if(T->left != NULL) S.push(T->left);
		}
	}
	return ans;
}

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		if(root == NULL) return ans;
        return postorder(root);
    }
};

/////////////////////
Solution g;

int main(void)
{
	Node *root = new Node(1);
	root->left = new Node(2); root->left->left = new Node(3);
	root->left->right = new Node(4); root->right = new Node(5);
	root->right->left = new Node(6);
	vector<int> ans = g.postorderTraversal(root);
	for(int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	printf("\n");
	system("pause");
	return 0;
}
