#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if(!n) return 0;
		int p = 1;
        for(int i = 1; i < n; i++)
        	if(A[i] != A[i-1])
        		 A[p++] = A[i];
		return p;        
    }
};

////////////
Solution g;
int main()
{
	int A[10] = {1, 2, 3, 4};
	int len = g.removeDuplicates(A, 4);
	for(int i = 0; i < len; i++)
		printf("%d ", A[i]);
	printf("\n");
	
	system("pause");
}
