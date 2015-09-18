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
#include <bitset>
#include <stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode Node;

bool dfs(Node *LeftSubTree, Node *RightSubTree)
{
	if(LeftSubTree == NULL && RightSubTree == NULL)
		return true;
	if((LeftSubTree != NULL && RightSubTree == NULL) || 
	   (LeftSubTree == NULL && RightSubTree != NULL))
	   		return false;
	if(LeftSubTree->val != RightSubTree->val)
		return false;
	if(dfs(LeftSubTree->left, RightSubTree->right) && dfs(LeftSubTree->right, RightSubTree->left))
		return true;
	else return false;
}

bool valid(Node *root)
{
	if(root == NULL) return true;
	return dfs(root->left, root->right);
}

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return valid(root);
    }
};

////////////////////////
Solution g;

int main()
{
	Node *root = new Node(5);
	root->left = new Node(4); root->right = new Node(1);
	root->left->right = new Node(1); root->right->right = new Node(4);
	root->left->right->left = new Node(2); root->right->right->left = new Node(2);
	
	if(g.isSymmetric(root))
		printf("valid\n");
	else
		printf("invalid\n");
	system("pause");
}
