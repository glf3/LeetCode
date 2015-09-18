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

const int INF = 0x3f3f3f3f;
int process(vector<int> &a, const int target)
{
	if(a.size() == 3) return a[0]+a[1]+a[2];
	sort(a.begin(), a.end());
	int minval = INF, val;
	for(int i = 0; i < a.size()-2; i++)
	{
		if(i >= 1 && a[i] == a[i-1]) continue ;
		int p1 = i+1, p2 = a.size()-1;
		while(p1 < p2)
		{
			int sum = a[p1]+a[p2]+a[i];
			if(abs(sum-target) <= minval)
				{ minval = abs(sum-target); val = sum; }
			if(sum > target)
				p2--;
			else if(sum < target)
				p1++;
			else if(sum == target)
				return val;
		}
	}
	return val;
}

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        return process(num, target);
    }
};

//////////////////////
Solution g;

int main(void)
{
	vector<int> num;
	/*Case 1#:num.push_back(-1), num.push_back(2), num.push_back(1), num.push_back(-4);*/ 
	
	/*Case 2#:num.push_back(4), num.push_back(0), num.push_back(5), num.push_back(-5); //4,0,5,-5,3,3,0,-4,-5
	num.push_back(3), num.push_back(3), num.push_back(0), num.push_back(-4);num.push_back(-5);*/
	
	num.push_back(1), num.push_back(2), num.push_back(4), num.push_back(8);
	num.push_back(16), num.push_back(32), num.push_back(64), num.push_back(128);
	printf("%d\n", g.threeSumClosest(num, 82));
	system("pause");
	return 0;
}
