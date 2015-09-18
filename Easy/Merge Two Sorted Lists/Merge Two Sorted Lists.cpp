#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *l3 = NULL, *head = NULL;
        int first = 1;
        while(l1 != NULL && l2 != NULL)
        {
			if(first)
			{
				if(l1->val < l2->val)
					 { l3 = new ListNode(l1->val); l1 = l1->next; }
				else { l3 = new ListNode(l2->val); l2 = l2->next; }
				head = l3;
				first = 0;
			}
			else
			{
				if(l1->val < l2->val)
				 	{ l3->next = new ListNode(l1->val); l1 = l1->next; }
				else
					{ l3->next = new ListNode(l2->val); l2 = l2->next; }
				l3 = l3->next;
			}
		}
		while(l1 != NULL)
		{
			if(first)
			{
				l3 = new ListNode(l1->val); l1 = l1->next;
				head = l3;
				first = 0;
			}
			else
			{
				l3->next = new ListNode(l1->val);
				l1 = l1->next;
				l3 = l3->next;
			}
		}
		while(l2 != NULL)
		{
			if(first)
			{
				l3 = new ListNode(l2->val); l2 = l2->next;
				head = l3;
				first = 0;
			}
			else
			{
				l3->next = new ListNode(l2->val);
				l2 = l2->next;
				l3 = l3->next;
			}
		}
		return head;
    }
};

//////////////
Solution g;

void print(ListNode *head)
{
	while(head != NULL)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	/*ListNode *l1 = new ListNode(10);
	l1->next = new ListNode(7);*/
	
	ListNode *l1 = NULL;
	ListNode *l2 = new ListNode(1);
	l2->next = new ListNode(20);
	
	ListNode *head = g.mergeTwoLists(l1, l2);
	print(head);
	
	system("pause");
	return 0;
}
