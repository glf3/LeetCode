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

typedef long long LL;
const LL INF = 10000000000000000LL;

/* Solution 1
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
		vector<LL> a;
		a.push_back(-INF);
        for(int i = 0; i < num.size(); i++)
        	a.push_back(1LL*num[i]);
        a.push_back(-INF);
        for(int i = 1; i < a.size()-1; i++)
        	if(a[i] > a[i-1] && a[i] > a[i+1])
        		return (i-1);
    }
};*/

/*
*	Solution 2
*/
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
		const vector<int> &A = num;
		if(A.size() <= 1) return 0;
		int x = 0, y = num.size()-1;
		while(x <= y)
		{
			int mid = x+(y-x)/2;
			if(x == y) return x;
			else if(A[mid] < A[mid+1])
				x = mid+1;
			else
				y = mid;
		}
    }
};

////////////////////
Solution g;

int main()
{
	vector<int> num;
	num.push_back(1), num.push_back(2), num.push_back(1);
	printf("%d\n", g.findPeakElement(num));
	system("pause");
	return 0;
}
