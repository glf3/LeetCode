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

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode Node;
Node *rebuild(ListNode *&l1, int x, int y)
{
	if(x > y) return NULL;
	int mid = x+(y-x)/2;
	Node *l = rebuild(l1, x, mid-1);
	Node *p = new Node(l1->val);
	l1 = l1->next;
	p->left = l;
	p->right = rebuild(l1, mid+1, y);
	return p;
}

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *l1 = head;
        int size = 0;
        for(;l1 != NULL; l1 = l1->next)
        	size++;
        return rebuild(head, 0, size-1);
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
	ListNode *l = new ListNode(1); l->next = new ListNode(2); l->next->next = new ListNode(3);
	l->next->next->next = new ListNode(4);
	Node *t = g.sortedListToBST(l);
	preorder(t); printf("\n");
	system("pause");
	return 0;
}
