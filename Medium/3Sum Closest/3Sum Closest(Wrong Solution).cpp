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

/*
* This solution may lose some status, so it's wrong.
*/

const int INF = 0x3f3f3f3f;
int process(vector<int> &a, const int target)
{
	if(a.size() == 3) return a[0]+a[1]+a[2];
	sort(a.begin(), a.end());
	int p1 = 0, p2 = a.size()-1;
	int minval = INF, val = 0;
	while(p1 < p2)
	{
		int sum = a[p1]+a[p2];
		for(int i = p1+1; i <= p2-1; i++)
		{
			int tmp = sum+a[i];
			if(abs(tmp-target) <= minval)
				{ minval = abs(tmp-target); val = tmp; }
		}
		if(val > target)
			p2--;
		else if(val < target)
			p1++;
		else if(val == target)
			return target;
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
	/* num.push_back(-1), num.push_back(2), num.push_back(1), num.push_back(-4); */
	num.push_back(4), num.push_back(0), num.push_back(5), num.push_back(-5); //4,0,5,-5,3,3,0,-4,-5
	num.push_back(3), num.push_back(3), num.push_back(0), num.push_back(-4);
	num.push_back(-5);
	printf("%d\n", g.threeSumClosest(num, -2));
	system("pause");
	return 0;
}
