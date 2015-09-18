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

vector<int> inorder(Node *root)
{
	vector<int> ans;
	if(root == NULL) return ans;
	stack<Node*> S;
	Node *T = root;
	while(T != NULL || !S.empty())
	{
		for(; T != NULL; T = T->left)
			S.push(T);
		T = S.top(); S.pop();
		ans.push_back(T->val);
		T = T->right;
	}
	return ans;
}

vector<int> process(Node *root)
{
	return inorder(root);
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        return process(root);
    }
};

//////////////////
Solution g;

int main(void)
{
	Node *root = new Node(1); root->right = new Node(2); root->right->left = new Node(3);
	vector<int> ans = g.inorderTraversal(root);
	for(int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	printf("\n");
	printf("%d\n", ans.size());
	system("pause");
}
