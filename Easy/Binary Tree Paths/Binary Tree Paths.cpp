#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode Node;

string change(int val)
{
	stringstream ss;
	string t;
	ss << val;
	ss >> t;
	return t;	
}

void dfs(Node *root, vector<string> &ans, string path)
{
	if(root->left == NULL && root->right == NULL)
	{
		path += change(root->val);
		ans.push_back(path);
		return ;
	}
	
	Node *tmp = root;
	path += change(tmp->val); path += "->";
	if(tmp->left != NULL)
		 dfs(tmp->left, ans, path);
	if(tmp->right != NULL)
		dfs(tmp->right, ans, path);
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ans;
		if(root == NULL) return ans;
        dfs(root, ans, "");
        /*for(int i = 0; i < ans.size(); i++)
        	cout << ans[i] << endl;*/
        return ans;
    }
};

//////////////
Solution g;

int main(void)
{
	Node *root = new Node(1);
	root->left = new Node(2); root->right = new Node(3);
	root->left->right = new Node(5);
	g.binaryTreePaths(root);
	system("pause");
}
