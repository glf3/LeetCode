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
bool process(Node *head)
{
	if(head == NULL || head->next == NULL)
		return false;
	Node *p1 = head, *p2 = head;
	while(p1 != NULL && p2 != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
		if(p2 != NULL) p2 = p2->next;
		if(p1 == p2) return true;
	}
	return false;
}

class Solution {
public:
    bool hasCycle(ListNode *head) {
        return process(head);
    }
};

///////////////////
Solution g;

int main(void)
{
	Node *head = new Node(1), *p1 = new Node(2), *p2 = new Node(3);
	Node *p3 = new Node(4);
	head->next = p1; p1->next = p2; p2->next = p3; //p3->next = head;
	if(g.hasCycle(head))
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
	return 0;
}


