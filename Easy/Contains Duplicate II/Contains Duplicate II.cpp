#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> hash;
        int n = nums.size();
        if(n == 1) return false;
        if(n <= k)
        {
			for(int i = 0; i < k && i < n; i++)
    			if(hash.count(nums[i]))
    				return true;
    			else
    				hash.insert(nums[i]);
    		return false;
		}
		else
		{
			for(int i = 0; i < k && i < n; i++)
    			if(hash.count(nums[i]))
    				return true;
    			else
    				hash.insert(nums[i]);
			int p1 = 0, p2 = k;
			while(p1 < p2 && p2 < n)
			{
				hash.clear();
				for(int i = p1; i <= p2; i++)
					if(hash.count(nums[i]))
						return true;
					else
						hash.insert(nums[i]);
				p1++; p2++;
			}
			return false;
		}
    }
};

/////////////////
Solution g;

int main(void)
{
	vector<int> a;
	a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(1);
	if(g.containsNearbyDuplicate(a, 2))
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
	return 0;
}
