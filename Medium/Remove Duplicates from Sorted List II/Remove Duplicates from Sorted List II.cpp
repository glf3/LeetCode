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
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

typedef ListNode Node;

Node *process(Node *head)
{
	map<int, int> a;
	a.clear();
	Node *l1 = head;
	vector<int> b;
	for(; l1 != NULL; l1 = l1->next)
	{
		b.push_back(l1->val);
		if(!a.count(l1->val))
			a[l1->val] = 1;
		else if(a.count(l1->val))
			a[l1->val] = -1;
	}
	int i;
	Node* newHead = NULL, *l2 = NULL;
	int first = 1;
	for(i = 0; i < b.size(); i++)
		if(a[b[i]] == 1)
		{
			if(first) { newHead = new Node(b[i]); first = 0; l2 = newHead;}
			else
				 { l2->next = new Node(b[i]); l2 = l2->next; }
		}
	return newHead;
}

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		if(head == NULL)
			return NULL;
    	return process(head);
    }
};

////////////////
Solution g;

int main()
{
	Node *head = new Node(1);
	head->next = new Node(2); head->next->next = new Node(3);
	head->next->next = new Node(4); head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	Node *l1 = g.deleteDuplicates(head);
	for(; l1 != NULL; l1 = l1->next)
		printf("%d ", l1->val);
	printf("\n");
	system("pause");
}
