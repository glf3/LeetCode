#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode Node;

/*Solution 1*/
Node* invert(Node *root)
{
	queue<Node*> Q;
	Q.push(root);
	while(!Q.empty())
	{
		Node *cur = Q.front(); Q.pop();
		Node *tmp = cur->left;
		cur->left = cur->right;
		cur->right = tmp;
		if(cur->left) Q.push(cur->left);
		if(cur->right) Q.push(cur->right);
	}
	return root;
}

/* Solution 2*/
/*Node *invert(Node *root)
{
	if(root == NULL) return NULL;
	Node *newroot = new Node(root->val);
	newroot->left = invert(root->right);
	newroot->right = invert(root->left);
	return newroot;
}*/

/*test*/
void preorder(Node *root)
{
	if(root == NULL) return ;
	printf("%d\n", root->val);
	preorder(root->left);
	preorder(root->right);
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
		if(root == NULL) return NULL;
        Node *newroot = invert(root);
        //preorder(newroot);
    }
};

///////////////
Solution g;

int main(void)
{
	Node *root = new Node(4);
	root->left = new Node(2); root->right = new Node(7);
	root->left->left = new Node(1); root->left->right = new Node(3);
	root->right = new Node(7); root->right->left = new Node(6); 
	root->right->right= new Node(9);
	Node *newroot = g.invertTree(root);
	system("pause");
}
