#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode Node;
vector<vector<int> > ans;

void dfs(Node *root, int sum, vector<int> path)
{
	if(root == NULL)
		return ;
	path.push_back(root->val);
	if(root->left == NULL && root->right == NULL)
	{
		if(root->val == sum)
			ans.push_back(path);
	}
	if(root->left != NULL) dfs(root->left, sum-(root->val), path);
	if(root->right != NULL) dfs(root->right, sum-(root->val), path);
}

vector<vector<int> > cal(Node *root, int sum)
{
	vector<int> path;
	for(int i = 0; i < ans.size(); i++)	
		ans.clear();
	dfs(root, sum, path);
	return ans;
}

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        return cal(root, sum);
    }
};

//////////////
Solution g;

int main()
{
	Node *root = new Node(5);
	root->left = new Node(4); root->right = new Node(8);
	root->left->left = new Node(11), root->left->left->left = new Node(7); 
	root->left->left->right = new Node(2);
	root->right->left = new Node(13); root->right->right = new Node(4);
	root->right->right->left = new Node(5), root->right->right->right = new Node(1);
	
	ans = g.pathSum(root, 22);
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
		{
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
