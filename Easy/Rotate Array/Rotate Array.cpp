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
    void rotate(int nums[], int n, int k) {
		k %= n;
		if(k == 0)
			return ;
		vector<int> T;
		for(int i = 0; i < k; i++)
			T.push_back(nums[n-i-1]);
		reverse(T.begin(), T.end());
		
		for(int i = 0; i < n-k; i++)
			T.push_back(nums[i]);
		for(int i = 0; i < T.size(); i++)
			nums[i] = T[i];
    }
};

/////////////////
Solution g;

int main(void)
{
	int nums[7] = {1, 2, 3, 4, 5, 6, 7};
	g.rotate(nums, 7, 8);
	for(int i = 0; i < 7; i++)
		printf("%d ", nums[i]);
	printf("\n");
	system("pause");
}
