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

class Solution {
public:
    bool search(int A[], int n, int target) {
		sort(A, A+n);
		int p = lower_bound(A, A+n, target)-A;
        if(p < n && A[p] == target)
        	return true;
        else
			return false;
    }
};

///////////////
Solution g;

int main(void)
{
	int a[10] = {0, 0, 0};
	if(g.search(a, 3, -5))
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
	return 0;
}
