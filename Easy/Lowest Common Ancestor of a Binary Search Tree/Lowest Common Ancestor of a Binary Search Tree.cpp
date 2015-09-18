#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode Node;

Node *search(Node *root, Node *p, Node *q)
{
	if(p->val <= root->val && q->val >= root->val)
		return root;
	else if(p->val >= root->val && q->val <= root->val)
		return root;
	else if(p->val < root->val && q->val < root->val && root->left != NULL)
		search(root->left, p, q);
	else if(p->val > root->val && q->val > root->val && root->right != NULL)
		search(root->right, p, q);
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if(root == NULL) return NULL;
        return search(root, p, q);
    }
};

///////////////////
Solution g;

int main(void)
{
	return 0;
}
