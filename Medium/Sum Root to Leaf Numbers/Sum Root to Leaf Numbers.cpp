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

void dfs(Node *root, int val, int &ans)
{
	if(root->left == NULL && root->right == NULL)
	{
		ans += (val+root->val);
		return ;
	}
	if(root->left != NULL)
	{
		int tmp = val;
		tmp += root->val;
		dfs(root->left, tmp*10, ans);
	}
	if(root->right != NULL)
	{
		int tmp = val;
		tmp += root->val;
		dfs(root->right, tmp*10, ans);
	}
}

int calculate(Node *root)
{
	if(root == NULL)
		return 0;
	int ans = 0;
	dfs(root, 0, ans);
	return ans;
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
	Node *root = new Node(0);
	root->left = new Node(1);
	root->left->left = new Node(5);
	root->left->right = new Node(10);
	printf("%d\n", g.sumNumbers(root));
	system("pause");
	return 0;
}
