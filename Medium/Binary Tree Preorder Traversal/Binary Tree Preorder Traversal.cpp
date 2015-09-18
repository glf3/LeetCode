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

vector<int> preorder(Node *root)
{
	stack<Node*> S;
	vector<int> ans;
	if(root == NULL) return ans;
	Node* T = root;
	while(T != NULL || !S.empty())
	{
		for(; T != NULL; T = T->left)
			 { S.push(T); ans.push_back(T->val); }
		T = S.top(); S.pop();
		T = T->right;
	}
	return ans;
}

vector<int> process(Node *root)
{
	return preorder(root);
}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        return process(root);
    }
};


int main()
{
	
}
