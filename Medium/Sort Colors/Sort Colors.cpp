#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

class Solution {
public:
	Solution()
	{
		memset(hash, 0, sizeof(hash));
	}
    void sortColors(int A[], int n) {
        for(int i = 0; i < n; i++)
        	hash[A[i]]++;
        int k = 0;
        for(int i = 0; i < 3; i++)
        for(int j = 0; j < hash[i]; j++)
        	A[k++] = i;
    }
private:
	int hash[3];
};
