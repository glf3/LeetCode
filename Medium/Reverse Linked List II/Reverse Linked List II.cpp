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

Node *pm1, *pm2;

void reverse(Node *head, Node* pre, Node *&newHead, int count, int m, int n)
{
	if(count == n || head->next == NULL)
	{
		pm1 = head, pm2 = head->next;
		head->next = pre;
		newHead = head;
		return ;
	}
	reverse(head->next, head, newHead, count+1, m, n);
	if(m <= count && count <= n)
	{
		if(count == m)
		{
			if(pre != NULL)
				pre->next = pm1;
			head->next = pm2;
		}
		else
			head->next = pre;
	}
}

Node* process(Node *head, int m, int n)
{
	Node* newHead = NULL;
	reverse(head, NULL, newHead, 1, m, n);
	return newHead;
}

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
		if(head == NULL) return NULL;
		if(m == n) return head;
        Node *newHead = process(head, m, n);
        if(m == 1)
        	return newHead;
        return head;
    }
};

void print(Node *l1)
{
	for(;l1 != NULL; l1 = l1->next)
		printf("%d ", l1->val);
	printf("\n");
}

//////////////////
Solution g;

int main(void)
{
	Node *head = new Node(1), *p1 = new Node(2), *p2 = new Node(3), *p3 = new Node(4);
	Node *p4 = new Node(5);
	head->next = p1; p1->next = p2; p2->next = p3; p3->next = p4;
	Node *newHead = g.reverseBetween(head, 2, 4);
	print(newHead);
	system("pause");
	return 0;
}
