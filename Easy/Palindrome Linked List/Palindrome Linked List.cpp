#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

typedef ListNode Node;

void reverse(Node *head, Node *pre, Node *&newHead)
{
	if(head->next == NULL)
	{
		newHead = head;
		newHead->next = pre;
		return ;
	}
	reverse(head->next, head, newHead);
	head->next = pre;
}

bool process(Node *head)
{
	Node *newHead, *l1 = head;
	vector<int> a;
	for(l1; l1; l1 = l1->next)
		a.push_back(l1->val);
	int n = a.size();
	
	reverse(head, NULL, newHead);
	for(int i = 0; i < n/2; i++)
	{
		if(a[i] != newHead->val)
			return false;
		newHead = newHead->next;
	}
	return true;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
		if(head == NULL) return true;
        return process(head);
    }
};


/*
TLE solution

class Solution {
public:
    bool isPalindrome(ListNode* head) {
		if(head == NULL) return true;
        Node *l1 = head, *l2 = l1;
        int n = 0;
        for(l1; l1 != NULL; l1 = l1->next)
        	n++;
        l1 = head;   
        for(int i = 0; i < n/2; i++)
        {
			l2 = head;
			for(int j = 0; j < n-i-1; j++)
				l2 = l2->next;
			if(l1->val != l2->val)
				return false;
			l1 = l1->next;
		}
		return true;
    }
};
*/

/////////////////////////
Solution g;

int main(void)
{
	/*Node *l1 = new Node(1);
	l1->next = new Node(1); l1->next->next = new Node(0); l1->next->next->next = new Node(0);
	l1->next->next->next->next = new Node(1);*/
	Node *l1 = new Node(1);
	l1->next = new Node(3); l1->next->next = new Node(1); 
	if(g.isPalindrome(l1))
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
}
