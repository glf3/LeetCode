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

typedef ListNode Node;

Node* process(Node *root, int k)
{
	Node *l1 = root, *pre = NULL;
	if(k == 0 || root->next == NULL) return root;
	int size = 0;
	for(;; pre = l1, l1 = l1->next)
		if(l1 == NULL)
			 { pre->next = root; break; }
		else
			size++;
	k %= size;
	l1 = root;
	for(; size > k+1; l1 = l1->next, size--) ;
	Node *newHead = l1->next;
	l1->next = NULL;
	return newHead;
}

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
		if(head == NULL) return NULL;
        return process(head, k);
    }
};

//////////////////
Solution g;

int main(void)
{
	Node *l1 = new Node(1), *p1 = new Node(2), *p2 = new Node(3);
	Node *p3 = new Node(4), *p4 = new Node(5);
	l1->next = p1, p1->next = p2, p2->next = p3, p3->next = p4;
	Node *l2 = g.rotateRight(l1, 2);
	for(;l2 != NULL; l2 = l2->next)
		printf("%d ", l2->val);
	printf("\n");
	system("pause");
}
