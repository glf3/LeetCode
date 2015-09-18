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

void preorder(Node *root, vector<Node*> &a)
{
	if(root != NULL)
	{
		a.push_back(root);
		if(root->left != NULL)
			preorder(root->left, a);
		if(root->right != NULL)
			preorder(root->right, a);
	}
}

class Solution {
public:
    void flatten(TreeNode *root) {
        	if(root == NULL) return ;
		vector<Node*> save;
		preorder(root, save);
		int sz = save.size();
		for(int i = 0; i < sz-1; i++)
			 { save[i]->right = save[i+1]; save[i]->left = NULL; }
		save[sz-1]->right = NULL;
    }
};

/////////////////
Solution g;

void print(Node *root)
{
	while(root != NULL)
	{
		printf("%d ", root->val);
		root = root->right;
	}
	printf("\n");
}

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2), root->right = new Node(5);
	root->left->left = new Node(3), root->left->right = new Node(4);
	root->right->right = new Node(6);
	g.flatten(root);
	print(root);
	system("pause");
}
