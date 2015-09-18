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

#ifdef OK
/* Solution 1 */
typedef map<int, int>::iterator It;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
		map<int, int> Map;
		for(int i = 0; i < nums.size(); i++)
			Map[nums[i]]++;
		vector<int> a;
		for(It it = Map.begin(); it != Map.end(); it++)
			if(it->second == 1)
				a.push_back(it->first);
		return a;
    }
};
#else
/* Solution 2 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
		vector<int> &a = nums;
		int n = a.size();
		int val = 0;
		for(int i = 0; i < n; i++)
			val ^= a[i];
		int lastBit = val&(~(val-1)); /*Get the lastbit of val*/
		
		int x = 0, y = 0;
		for(int i = 0; i < n; i++)
			if(lastBit&(a[i]))
				x ^= a[i];
			else
				y ^= a[i];
		vector<int> b;
		b.push_back(x), b.push_back(y);
		//printf("%d %d\n", x, y);
		return b;
    }
};
#endif

//////////////////////
Solution g;

int main(void)
{
	vector<int> a;
	a.push_back(1); a.push_back(2); a.push_back(1);
	a.push_back(3); a.push_back(2); a.push_back(5);
	g.singleNumber(a);
	system("pause");
	return 0;
}
