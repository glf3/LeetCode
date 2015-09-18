#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
using namespace std;

class Stack {
public:
	deque<int> dq;
    // Push element x onto stack.
    void push(int x) {
        dq.push_front(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        dq.pop_front();
    }

    // Get the top element.
    int top() {
        return dq.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return dq.empty();
    }
};

///////////////////////
Stack g;

int main(void)
{
	g.push(1); g.push(2); g.push(3);
	printf("%d\n", g.top());
	g.pop();
	printf("%d\n", g.top());
	system("pause");
	return 0;
}
