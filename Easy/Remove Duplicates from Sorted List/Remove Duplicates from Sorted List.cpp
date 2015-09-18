#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

typedef ListNode Node;
typedef map<int, bool> Map;
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        Node *l3, *newHead;
        Map Ma;
        vector<int> cache;
        if(head == NULL) return NULL;
        for(; head != NULL; head = head->next)
        	if(!Ma.count(head->val)) { Ma[head->val] = true; cache.push_back(head->val); }
        int first = 1;
        
        for(int i = 0; i < cache.size(); i++)
        {
			if(first) { l3 = new Node(cache[i]); newHead = l3; first = 0; }
			else
			{
				l3->next = new Node(cache[i]);
				l3 = l3->next;
			}
		}
		return newHead;
    }
};

////////////////
Solution g;

int main()
{
	Node *head;
	Node *l1 = new Node(9);
	head = l1;
	
	l1->next = new Node(7);
	l1->next->next = new Node(6);
	l1->next->next->next = new Node(7);
	for(; head != NULL; head = head->next)
		printf("%d ", head->val);
	printf("\n");
	Node *l2 = g.deleteDuplicates(l1);
	for(; l2 != NULL; l2 = l2->next)
		printf("%d ", l2->val);
	printf("\n");
	system("pause");
}
