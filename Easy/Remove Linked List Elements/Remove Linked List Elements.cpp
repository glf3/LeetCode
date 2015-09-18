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
Node *process(Node *head, int val)
{
	vector<int> a;
	Node *l1 = head;
	for(; l1 != NULL; l1 = l1->next)
		if(l1->val != val)
			a.push_back(l1->val);
	int first = 1;
	Node *newHead = NULL;
	for(int i = 0; i < a.size(); i++)
	{
		if(first) { newHead = new Node(a[i]); l1 = newHead; first = 0; }
		else
		{
			l1->next = new Node(a[i]);
			l1 = l1->next;
		}
	}
	return newHead;
}

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		if(head == NULL) return head;
        return process(head, val);
    }
};

//////////////////////////
Solution g;

int main(void)
{
	Node *l1 = new Node(1); l1->next = new Node(2); l1->next->next = new Node(6);
	l1->next->next->next = new Node(3); l1->next->next->next->next = new Node(5);
	l1->next->next->next->next->next = new Node(6);
	Node *newHead = g.removeElements(l1, 6);
	for(;newHead != NULL; newHead = newHead->next)
		printf("%d ", newHead->val);
	printf("\n");
	system("pause");
}
