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
    bool containsDuplicate(vector<int>& nums) {
		set<int> hash;
		if(nums.size() == 0)
			return false;
        for(int i = 0; i < nums.size(); i++)
        	if(hash.count(nums[i]))
				return true;
        	else
        		hash.insert(nums[i]);
        return false;
    }
};



////////////////
Solution g;


int main(void)
{
	
}
