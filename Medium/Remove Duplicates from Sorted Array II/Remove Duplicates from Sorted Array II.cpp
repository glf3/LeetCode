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

typedef map<int, int>::iterator It;
int process(int A[], int n)
{
	map<int, int> mp;
	for(int i = 0; i < n; i++)
			mp[A[i]]++;
	memset(A, 0, sizeof(A));
	int size = 0;
	for(It it = mp.begin(); it != mp.end(); it++)
	{
		A[size++] = it->first;
		if(it->second > 1)
			A[size++] = it->first;
	}
	return size;
}

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        return process(A, n);
    }
};

///////////////
Solution g;

int main(void)
{
	int A[10] = {1, 1, 1, 2, 2, 3};
	printf("%d\n", g.removeDuplicates(A, 6));
	system("pause");
	return 0;
}
