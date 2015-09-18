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

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<Node*> S;
        for(Node *h1 = headA; h1 != NULL; h1 = h1->next)
        	S.insert(h1);
        for(Node *h2 = headB; h2 != NULL; h2 = h2->next)
        	if(S.count(h2))
        		return h2;
        return NULL;
    }
};

////////////////

Solution g;

int main(void)
{
	Node *headA = new Node(1), *h2 = new Node(103), *h3 = new Node(3);
	Node *headB = new Node(2);
	headA->next = h2; h2->next = h3;
	headB->next = h2;
	Node *p = g.getIntersectionNode(headA, headB);
	printf("%d\n", p->val);
	system("pause");
	return 0;
}
