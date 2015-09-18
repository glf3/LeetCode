#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode Node;

int find(const vector<int> &b, int x, int y, int val)
{
	for(int i = x; i <= y; i++)
		if(b[i] == val)
			return i;
	return -1;
}

int n, m;

Node* build(const vector<int> &a, const vector<int> &b, int afirst, int alast, int bfirst, int blast)
{
	if(afirst > alast) return NULL;
	if(bfirst > blast) return NULL;
	int val = a[afirst];
	Node *root = new Node(val);
	int p = find(b, bfirst, blast, val);
	int leftsize = p-bfirst;
	root->left = build(a, b, afirst+1, afirst+leftsize, bfirst, p-1);
	root->right = build(a, b, afirst+leftsize+1, alast, p+1, blast);
	return root;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		 vector<int> &a = preorder, &b = inorder;
         n = a.size(), m = b.size();
         if(n != m || (n == m && n == 0)) return NULL;
         int afirst = 0, alast = n-1, bfirst = 0, blast = m-1;
         return build(a, b, afirst, alast, bfirst, blast);
    }
};

/////////////////////
Solution g;

void print(Node *root)
{
	if(root != NULL)
	{
		print(root->left);
		print(root->right);
		printf("%d ", root->val);
	}
}

int main(void)
{
	vector<int> a, b;
	a.push_back(1); a.push_back(2); a.push_back(3);
	a.push_back(4); a.push_back(5); a.push_back(6);
	
	b.push_back(3); b.push_back(2); b.push_back(4);
	b.push_back(1); b.push_back(6); b.push_back(5);
	Node *root = g.buildTree(a, b);
	print(root);
	printf("\n");
	system("pause");
	return 0;
}
