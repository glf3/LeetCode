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

void cmp1(Node *root, int val, int &ans)
{
	if(ans) return ;
	if(root->val >= val)
		 { ans = 1; return ; }
	if(root->left == NULL && root->right == NULL)
		return ;
	if(root->left != NULL)
		cmp1(root->left, val, ans);
	if(root->right != NULL)
		cmp1(root->right, val, ans);
}

void cmp2(Node *root, int val, int &ans)
{
	if(ans) return ;
	if(root->val <= val)
		 { ans = 1; return ; }
	if(root->left == NULL && root->right == NULL)
		return ;
	if(root->left != NULL)
		cmp2(root->left, val, ans);
	if(root->right != NULL)
	cmp2(root->right, val, ans);	
}

void dfs(Node *root, int &ans)
{
	if(ans) return ;
	if(root->left == NULL && root->right == NULL)
		return ;
	if(root->left != NULL)
	{
		int ans1 = 0;
		cmp1(root->left, root->val, ans1);
		if(ans1) { ans = 1; return ; }
		dfs(root->left, ans);
	}
	if(root->right != NULL)
	{
		int ans2 = 0;
		cmp2(root->right, root->val, ans2);
		if(ans2) { ans = 1; return ; }
		dfs(root->right, ans);
	}
}

bool ok(Node *root)
{
	if(root == NULL)
		return 1;
	int ans = 0;
	dfs(root, ans);
	return ans? 0 : 1;
}

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return ok(root);
    }
};

////////////
Solution g;

int main()
{
	Node *root = new Node(1);
	root->left = new Node(1);
	root->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(5);
	if(g.isValidBST(root))
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
}
