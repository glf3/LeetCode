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
    vector<int> searchRange(int A[], int n, int target) {
        int p1 = lower_bound(A, A+n, target)-A, p2 = upper_bound(A, A+n, target)-A;
        vector<int> ans;
        if(A[p1] != target && A[p2-1] != target)
        	p1 = -1, p2 = 0;
        ans.push_back(p1), ans.push_back(p2-1);
        return ans;
    }
};

//////////////
Solution g;

int main()
{
	int A[10] = {5, 7, 7, 8, 8, 10};
	vector<int> ans = g.searchRange(A, 6, 8);
	printf("%d %d\n", ans[0], ans[1]);
	system("pause");
	return 0;
}
