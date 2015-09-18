#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode Node;

void make_order(TreeNode *root, vector<int> &order)
{
	if(root != NULL)
	{
		make_order(root->left, order);
		order.push_back(root->val);
		make_order(root->right, order);
	}
}

bool ok(vector<int> order)
{
	int n = order.size();
	for(int i = 0; i < n; i++)
		if(order[i] != order[n-i-1]) return false;
	return true;
}

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
		return ok(root);
    }
};
/////////////////

Solution g;

int main()
{
	Node *root1 = new Node(1);
	root1->left = new Node(2);
	root1->left->left = new Node(3);
	root1->left->right = new Node(4);
	
	root1->right = new Node(2);
	root1->right->left = new Node(4);
	root1->right->right = new Node(3);
	
	Node *root2 = new Node(1);
	root2->left = new Node(2);
	root2->left->right = new Node(3);
	
	root2->right = new Node(2);
	root2->right->right = new Node(3);
	
	if(g.isSymmetric(root1)) printf("yes\n");
	else printf("no\n");
	
	if(g.isSymmetric(root2)) printf("yes\n");
	else printf("no\n");
	system("pause");
}
