#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode *root, int sum, int &ans)
{
	if(root == NULL) return ;
	if(root->left == NULL && root->right == NULL && sum == root->val) { ans = 1; return ; }
	dfs(root->left, sum-(root->val), ans);
	dfs(root->right, sum-(root->val), ans);
}

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
		int ans = 0;
		dfs(root, sum, ans);
		return ans;
    }
};
//////////////
Solution g;

void print(TreeNode *root)
{
	if(root == NULL) return ;
	printf("%d\n", root->val);
	print(root->left);
	print(root->right);
}

int main()
{
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	
	root->right = new TreeNode(8);
	root->right->right = new TreeNode(4);
	root->right->left = new TreeNode(13);
	root->right->right->right = new TreeNode(1);
	print(root);
	
	if(g.hasPathSum(root, 27)) printf("yes\n");
	else printf("no\n");
	
	system("pause");
}
