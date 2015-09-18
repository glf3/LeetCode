#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

typedef ListNode Node;
const int maxn = 10000 + 100;

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
		vector<int> r, t;
		if(head == NULL) return NULL;
        for(; head != NULL; head = head->next)
        	 { r.push_back(head->val); }
        bool vis[maxn] = {0};
        for(int i = 0; i < r.size(); i++)
        	if(r[i] < x)
        	 { vis[i] = true; t.push_back(r[i]); }
        for(int i = 0; i < r.size(); i++) if(!vis[i])
			t.push_back(r[i]);
		Node *l1 = NULL, *newhead = NULL;
		l1 = new Node(t[0]); newhead = l1;
		for(int i = 1; i < t.size(); i++)
			{ l1->next = new Node(t[i]); l1 = l1->next; }
		return newhead;
    }
};

void print(Node *head)
{
    for(; head != NULL; head = head->next)
        printf("%d ", head->val);
    printf("\n");
}

//////////////
Solution g;

int main()
{
	Node *l1 = NULL, *head = NULL;
	l1 = new Node(1); head = l1;
	l1->next = new Node(4), l1->next->next = new Node(3); l1->next->next->next = new Node(2);
	l1->next->next->next->next = new Node(5); l1->next->next->next->next->next = new Node(2);
	head = g.partition(head, 3);
	print(head);
	system("pause");
	return 0;
}
