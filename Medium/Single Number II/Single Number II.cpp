#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        sort(A, A+n);
        for(int i = 1, cnt = 1; i < n; i++)
        {
			if(A[i] == A[i-1])
				++cnt;
			else
			{
				if(cnt < 3)
					return A[i-1];
				else
					cnt = 1;
			}
		}
		return A[n-1];
    }
};

////////////
Solution g;

int main()
{
	int A[100] = {2, 2, 2, 10, 5, 5, 5, 4, 4, 4, 1, 1, 1};
	//int A[1000] = {17,12,5,-6,12,4,17,-5,2,-3,2,4,5,16,-3,-4,15,15,-4,-5,-61, 1};
	printf("%d\n", g.singleNumber(A, 13));
	system("pause");
	return 0;
}
