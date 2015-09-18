#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int Height(TreeNode *root)
{
	if(root == NULL) return 0;
	else return max(Height(root->left), Height(root->right))+1;
}

void dfs(TreeNode *root, int &ans)
{
	if(root == NULL) return ; 
	if(abs(Height(root->left) - Height(root->right)) > 1) { ans = 0; return ;}
	dfs(root->left, ans);
	dfs(root->right, ans);
}

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int ans = 1;
        dfs(root, ans);
        return ans;
    }
};

/////////////////
Solution g;

int main()
{
	TreeNode *root = new TreeNode(5);
	/*root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	
	root->right = new TreeNode(8);
	root->right->right = new TreeNode(4);
	root->right->left = new TreeNode(13);
	root->right->right->right = new TreeNode(1);*/
	root->left = new TreeNode(1), root->right = new TreeNode(5);
	if(g.isBalanced(root)) printf("yes\n");
	else printf("no\n");
	
	system("pause");
	return 0;
}
