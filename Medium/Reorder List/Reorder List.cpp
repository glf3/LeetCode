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
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

typedef ListNode Node;

void print(Node *head)
{
	for(; head != NULL; head = head->next)
		printf("%d\n", head->val);
}

class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL)
			return ;
		Node *l1 = head;
		vector<Node*> a;
		for(; l1 != NULL; l1 = l1->next)
			a.push_back(l1);
		int p1 = 0, p2 = a.size()-1;
		while(p1 < p2)
		{
			a[p1]->next = a[p2];
			a[p2--]->next = a[++p1];
		}
		a[p1]->next = NULL;
    }
};

///////////////
Solution g;

int main()
{
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	//head->next->next->next = new Node(4);
	g.reorderList(head);
	system("pause");
	return 0;
}
