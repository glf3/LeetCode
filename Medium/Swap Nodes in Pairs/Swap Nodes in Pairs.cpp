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

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
		if(head == NULL)
			return NULL;
		vector<int> a;
        Node *l1 = head;
        for(; l1 != NULL;)
        {
        	if(l1->next != NULL)
				a.push_back(l1->next->val);
			else { a.push_back(l1->val); break; }
			a.push_back(l1->val);
			if(l1->next != NULL)
				l1 = l1->next->next;
		}
		
		Node *newHead = NULL, *l2 = NULL;
		for(int i = 0, first = 1; i < a.size(); i++)
		{
			if(first) { newHead = new Node(a[i]); l2 = newHead; first = 0; }
			else
			{
				l2->next = new Node(a[i]);
				l2 = l2->next;
			}
		}
		return newHead;
    }
};

///////////////////
Solution g;

int main()
{
	Node* head = new Node(1);
	head->next = new Node(2); head->next->next = new Node(3); head->next->next->next = new Node(4);
	Node *newHead = g.swapPairs(head);
	for(; newHead != NULL; newHead = newHead->next)
		printf("%d ", newHead->val);
	printf("\n");
	system("pause");
}
