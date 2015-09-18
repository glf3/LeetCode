#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <queue>
using namespace std;

class MinStack {
public:
    void push(int x) {
        st.push(x);
        if(minst.empty() || x <= minst.top())
        	minst.push(x);
    }
    void pop() {
		int x;
        if(!st.empty())
        {
        	x = st.top();
			st.pop();
		}
		if(x == minst.top()) minst.pop();
    }
    int top() {
        if(!st.empty())
        	return st.top();
    }
    int getMin() {
        if(!minst.empty())
        	return minst.top();
    }
private:
	stack<int> st;
	stack<int> minst;
};

////////////
MinStack g;

int main()
{
	int cmd, x;
	while(~scanf("%d", &cmd))
	{
		if(cmd == 1)
		{
			scanf("%d", &x); g.push(x);
		}
		else if(cmd == 2)
		{
			g.pop();
		}
		else if(cmd == 3)
		{
			printf("%d\n", g.top());
		}
		else
		{
			printf("%d\n", g.getMin());
		}
	}
	return 0;
}
