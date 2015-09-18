#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

/*Solution 1*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for(int i = 0; i < n; i++)
        	A[m+i] = B[i];
        sort(A, A+m+n);
    }
};

/*Solution 2*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
		int C[m+n];
		int p1 = 0, p2 = 0, p3 = 0;
		while(p1 < m && p2 < n)
		{
			if(A[p1] < B[p2])
				{ C[p3++] = A[p1]; p1++; }
			else
				{ C[p3++] = B[p2]; p2++; }
		}
		while(p1 < m)
			C[p3++] = A[p1++];
		while(p2 < n) C[p3++] = B[p2++];
		memcpy(A, C, sizeof(C));
    }
};
