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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int n = gas.size();
		int T = 0;
		for(int i = 0; i < n; i++)
			T += gas[i]-cost[i];
		if(T < 0) return -1;
		
		int res = gas[0]-cost[0];
		int start = 0;
		for(int i = 1; i < n; i++)
		{
			if(res >= 0)
				res += gas[i]-cost[i];
			else
				{ start = i; res = gas[i]-cost[i]; }
		}
		return start;
    }
};

//////////////////////
Solution g;

int main(void)
{
	vector<int> gas, cost;
	gas.push_back(6); gas.push_back(1); gas.push_back(4); gas.push_back(3); gas.push_back(5);
	cost.push_back(3); cost.push_back(8); cost.push_back(2); cost.push_back(4); cost.push_back(2);
	printf("%d\n", g.canCompleteCircuit(gas, cost));
	system("pause");
	return 0;
}
