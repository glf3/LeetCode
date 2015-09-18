#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

typedef ListNode Node;

/*Solution 1*/
void reverse1(Node *pre, Node *l1, Node *&newHead)
{
	if(l1->next == NULL) { newHead = l1; l1->next = pre; return ; }
	reverse(l1, l1->next, newHead);
	l1->next = pre;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        Node *newHead = NULL;
        reverse1(NULL, head, newHead);
        return newHead;
    }
};

/*Solution  2*/
/*
void reverse2(Node *l1, Node *&newHead)
{
	Node *pre = NULL;
	Node *p1 = l1, *p2 = l1->next;
	for(;;)
	{
		p1->next = pre;
		if(p2 == NULL) { newHead = p1; return ; }
		pre = p1;
		p1 = p2;
		p2 = p2->next;
	}
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        Node *newHead = NULL;
        reverse2(head, newHead);
        return newHead;
    }
};
*/

///////////////////////
Solution g;

int main(void)
{
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	Node *l1 = g.reverseList(head);
	for(;l1; l1 = l1->next)
		printf("%d\n", l1->val);
	system("pause");
	return 0;
}
