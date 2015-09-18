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
Node *process(Node *head)
{
	if(head == NULL || head->next == NULL) return NULL;
	Node *p1 = head;
	set<Node*> vis;
	vis.insert(head);
	for(;;)
	{
		p1 = p1->next;
		if(p1 == NULL)
			return NULL;
		else if(vis.count(p1))
			return p1;
		else
			vis.insert(p1);
	}
	return NULL;
}

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        return process(head);
    }
};

///////////////
Solution g;

int main(void)
{
	Node *head = new Node(1), *p1 = new Node(2), *p2 = new Node(3);
	Node *p3 = new Node(4);
	head->next = p1; p1->next = p2; p2->next = p3; p3->next = p1;
	printf("%d\n", g.detectCycle(head)->val);
	system("pause");
	return 0;
}
