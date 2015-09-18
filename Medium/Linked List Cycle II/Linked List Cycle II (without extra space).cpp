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

/*刚进环的时候慢指针走了step,环的大小为n,快慢指针在距离环起点k步的时候相遇
*这是慢指针走了step+k步，快指针走了2*(step+k)步,快指针在圈内走了2*(step+k)-step=step+2*k步,
*由于相遇在k位置,所以(step+2*k)%n = k,即step+k = m*n
*慢指针已经走了k步了,再走step步时一定会回到圈的起点(step+k = m*n)
*/
typedef ListNode Node;
Node *process(Node *head)
{
	if(head == NULL || head->next == NULL)
		return NULL;
	if(head->next == head)
		return head;
	
	Node *slow = head, *fast = head;
	bool flag = 0;
	while(slow != NULL && fast != NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast != NULL) fast = fast->next;
		if(slow == fast) { flag = 1; break; }
	}
	if(!flag) return NULL;
	Node *p1 = head;
	for(; p1 != slow; p1 = p1->next, slow = slow->next) ;
	return p1;
}

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        return process(head);
    }
};

///////////////
Solution g;

int main()
{
	Node *head = new Node(1), *p1 = new Node(2), *p2 = new Node(3);
	Node *p3 = new Node(4);
	head->next = p1; p1->next = p2; p2->next = p3; p3->next = head;
	Node *p = g.detectCycle(head);
	if(p) printf("%d\n", p->val);
	system("pause");
	return 0;
}
