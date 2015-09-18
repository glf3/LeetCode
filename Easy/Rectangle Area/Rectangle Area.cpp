#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

struct node
{
	int x, y;
	node(int x=0, int y=0): x(x), y(y) {}
};

int cal(const node &A, const node &B, const node &C, const node &D)
{
	if(B.x <= C.x || D.x <= A.x || D.y <= A.y || C.y >= B.y)
		return 0;
	int x = min(B.x, D.x) - max(A.x, C.x);
	int y = min(B.y, D.y) - max(A.y, C.y);
	return x*y;
}

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        node a, b, c, d;
        a = node(A, B), b = node(C, D);
        c = node(E, F), d = node(G, H);
        int area1 = (b.x-a.x)*(b.y-a.y);
        int area2 = (d.x-c.x)*(d.y-c.y);
        int ans = area1+area2-cal(a, b, c, d);
        return ans;
    }
};

//////////////////
Solution g;

int main(void)
{
	printf("%d\n", g.computeArea(0, 0, 0, 0, -1, -1, 1, 1));
	system("pause");
	return 0;
}
