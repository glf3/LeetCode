#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

bool can(int A[], int n)
{
	if(n == 1) return true;
	
	int p = 0, pre = -1;
	for(; p < n; )
	{
		int length = A[p], tmp = p;
		int max_ = -1;
		for(int i = 0; i <= length; i++)
		{
			int newp = tmp+i;
			if(newp+A[newp] >= n-1) return true;
			if(newp+A[newp] >= max_)
				{ max_ = newp+A[newp]; p = newp; }
		}
		if(p <= pre) return false;
		pre = p;
	}
	return false;
}

class Solution {
public:
    bool canJump(int A[], int n) {
        return can(A, n);
    }
};

////////////
Solution g;

int main()
{
	int A[10] = {3,2,1,0,4};
	if(g.canJump(A, 5))
		printf("Yes\n");
	else printf("No\n");
	system("pause");
	return 0;
}
