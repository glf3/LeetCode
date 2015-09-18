#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int first = 1;
        ListNode *head = NULL, *pre = NULL;
        ListNode *newNode = NULL;
        int c = 0;
        while(l1 != NULL && l2 != NULL)
        {
			int res = l1->val+l2->val;
			newNode = new ListNode((res+c)%10); 
			if(first) { head = newNode; first = 0; }
			c = (res+c) / 10;
			if(pre != NULL) pre->next = newNode;
			pre = newNode;
			l1 = l1->next;
			l2 = l2->next;
		}
		while(l1 != NULL)
		{
			int res = l1->val;
			newNode = new ListNode((res+c)%10);
			pre->next = newNode;
			pre = newNode;
			c = (res+c) / 10;
			l1 = l1->next;
		}
		while(l2 != NULL)
		{
			int res = l2->val;
			newNode = new ListNode((res+c)%10);
			pre->next = newNode;
			pre = newNode;
			c = (res+c) / 10;
			l2 = l2->next;
		}
		if(c) pre->next = new ListNode(c);
		return head;
	}
};

void print(ListNode *a)
{
	while(a != NULL)
	{
		printf("%d\n", a->val);
		a = a->next;
	}
}

/*
[1] [9, 9]
[0, 0, 1]

[5], [5]
[0, 1]
*/
int main(void)
{
	Solution g;
	ListNode *l1 = NULL, *l2 = NULL, *h1 = NULL, *h2 = NULL;
	l1 = new ListNode(1); h1 = l1;
	l2 = new ListNode(9); h2 = l2;
	l2->next = new ListNode(9);
	ListNode *h3 = g.addTwoNumbers(h1, h2);
	while(h3 != NULL)
	{
		printf("%d ", h3->val);
		h3 = h3->next;
	}
	printf("\n");
	system("pause");
}
