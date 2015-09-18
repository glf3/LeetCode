#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int ans = 0;
        for(int i = 1; i < n; i++)
        	if(prices[i] > prices[i-1])
        		ans += prices[i]-prices[i-1];
        return ans;
    }
};
//////////////////
Solution g;

int main(void)
{
	
}
