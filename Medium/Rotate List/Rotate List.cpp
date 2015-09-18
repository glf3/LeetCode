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

Node *process(Node *root, int k)
{
	deque<int> dq;
	for(;root != NULL; root = root->next)
		dq.push_back(root->val);
	k %= dq.size();
	for(int i = 0; i < k; i++)
	{
		int b = dq.back(); dq.pop_back();
		dq.push_front(b);
	}
	int first = 1;
	Node *newHead = NULL, *l1 = NULL;
	for(int i = 0; i < dq.size(); i++)
		if(first) { l1 = new Node(dq[i]); first = 0; newHead = l1; }
		else
			{ l1->next = new Node(dq[i]); l1 = l1->next; }
	return newHead;
}

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
		if(head == NULL) return NULL;
        return process(head, k);
    }
};

/////////////////
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
