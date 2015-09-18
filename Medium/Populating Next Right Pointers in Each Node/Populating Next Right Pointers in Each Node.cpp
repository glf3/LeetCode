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

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

typedef TreeLinkNode Node;

class Solution {
public:
    void connect(TreeLinkNode *root) {
		if(root == NULL)
			return ;
        queue<Node*> q1;
        q1.push(root);
        root->next = NULL;
        for(;;)
        {
			if(q1.empty()) break;
			vector<Node*> V;
			queue<Node*> q2;
        	while(!q1.empty())
        	{
				Node *x = q1.front(); q1.pop();
				V.push_back(x);
				if(x->left != NULL)
					q2.push(x->left);
				if(x->right != NULL)
					q2.push(x->right);
			}
			q1 = q2;
			V[V.size()-1]->next = NULL;
			for(int i = V.size()-1; i >= 0; i--)
			{
				if(i-1 >= 0)
					V[i-1]->next = V[i];
			}
    	}
	}
};

/////////////
Solution g;

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	g.connect(root);
	printf("%d\n", root->left->next->val);
	system("pause");
	return 0;
}
