#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode Node;
void pre_order(Node *root, string &preorder)
{
	if(root == NULL) { preorder += "#"; return ;}
	string s; stringstream ss;
	ss << root->val;
	ss >> s;
	preorder += s;
	pre_order(root->left, preorder);
	pre_order(root->right, preorder);
}

void in_order(Node *root, string &inorder)
{
	if(root == NULL) { inorder += "#"; return ;}
	string s; stringstream ss;
	ss << root->val;
	ss >> s;
	in_order(root->left, inorder);
	inorder += s;
	in_order(root->right, inorder);
}

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        string p_preorder = "", p_inorder = "";
        string q_preorder = "", q_inorder = "";
        pre_order(p, p_preorder), in_order(p, p_inorder);
        pre_order(q, q_preorder), in_order(q, q_inorder);
        if(p_preorder == q_preorder && p_inorder == q_inorder)
        	return true;
        else return false;
    }
};

///////////
Solution g;

int main()
{
	/*Node *root1 = new Node(1);
	root1->left = new Node(2);
	root1->left->left = new Node(3);
	root1->left->right = new Node(4);
	
	root1->right = new Node(2);
	root1->right->left = new Node(4);
	root1->right->right = new Node(3);
	
	Node *root2 = new Node(1);
	root2->left = new Node(2);
	root2->left->left = new Node(3);
	root2->left->right = new Node(4);
	
	root2->right = new Node(2);
	root2->right->left = new Node(4);
	root2->right->right = new Node(3);*/
	
	Node *root1 = new Node(1);
	root1->left = new Node(1);
	
	Node *root2 = new Node(1);
	root2->right = new Node(1);
	if(g.isSameTree(root1, root2))
		printf("same\n");
	else
		printf("diffrent\n");
	system("pause");
	return 0;
}
