#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

typedef ListNode Node;
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		Node *l1 = head;
		
		int N = 0;
		for(; l1 != NULL; l1 = l1->next) ++N;
		if(n == N) return head->next;
		
		Node *pre = head, *newHead = head;
        for(int cnt = 1; head != NULL; head = head->next, ++cnt)
        {
			if(cnt != (N-n+1))
				pre = head;
			else
				 { pre->next = head->next; break; }
		}
		return newHead;
    }
};

/////////////////////
Solution g;

int main()
{
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	
	Node *newHead = g.removeNthFromEnd(head, 2);
	for(; newHead != NULL; newHead = newHead->next)
		printf("%d ", newHead->val);
	printf("\n");
	system("pause");
}
