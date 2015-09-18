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

int depth(TreeNode *root)
{
	if(root == NULL) return 0;
	if(root->left != NULL && root->right != NULL)
		return min(depth(root->left), depth(root->right))+1;
	else
	{
		if(root->left == NULL)
			return depth(root->right)+1;
		if(root->right == NULL)
			return depth(root->left)+1;
	}
}

class Solution {
public:
    int minDepth(TreeNode *root) {
        return depth(root);
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
	
	printf("***%d\n", g.minDepth(root));
	system("pause");
}
