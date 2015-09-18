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
Node* rebuild(int x, int y, vector<int> &num)
{
	if(x > y) return NULL;
	int mid = x+(y-x)/2;
	Node *l = rebuild(x, mid-1, num);
	Node *r = rebuild(mid+1, y, num);
	Node *root = new Node(num[mid]);
	root->left = l, root->right = r;
	return root;
}

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
		if(!num.size()) return NULL;
        return rebuild(0, num.size()-1, num);
    }
};

void preorder(Node *t)
{
	if(t == NULL) return ;
	printf("%d ", t->val);
	preorder(t->left);
	preorder(t->right);
}

///////////////////
Solution g;

int main(void)
{
	vector<int> a;
	a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(5);
	a.push_back(7); a.push_back(9); a.push_back(10);
	Node *t = g.sortedArrayToBST(a);
	preorder(t); printf("\n");
	system("pause");
	return 0;
}
