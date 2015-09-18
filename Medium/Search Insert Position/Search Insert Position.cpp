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

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
		int p = lower_bound(A, A+n, target)-A;
        return p;
    }
};

//////////////
Solution g;

int main()
{
	int A[10] = {1, 3, 5, 6};
	printf("%d\n", g.searchInsert(A, 4, 2));
	system("pause");
	return 0;
}
