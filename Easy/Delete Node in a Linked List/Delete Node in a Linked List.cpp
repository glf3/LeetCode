#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
    }
};

int main(void)
{
	
}
