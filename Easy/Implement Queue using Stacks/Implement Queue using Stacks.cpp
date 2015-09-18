#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

class Queue {
public:
	stack<int> S1, S2;
    // Push element x to the back of queue.
    void push(int x) {
		S1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
		if(S2.empty())
		{
			while(!S1.empty())
				 { S2.push(S1.top()); S1.pop(); }
		}
		S2.pop();
    }

    // Get the front element.
    int peek(void) {
		if(S2.empty())
		{
			while(!S1.empty())
				 { S2.push(S1.top()); S1.pop(); }
		}
		return S2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
		if(S1.empty() && S2.empty())
			return true;
		return false;
    }
};

//////////////////////
Queue g;

int main(void)
{
	g.push(1); g.pop();
	if(g.empty())
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
	return 0;
}
