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
using namespace std;

int cal(vector<int> &a)
{
	int maxarea = 0;
	int p1 = 0, p2 = a.size()-1;
	
	while(p1 < p2)
	{
		int x = min(a[p1], a[p2]);
		int y = abs(p1-p2);
		maxarea = max(maxarea, x*y);
		if(a[p1] > a[p2])
			p2--;
		else
			p1++;
	}
	return maxarea;
}

class Solution {
public:
    int maxArea(vector<int> &height) {
        return cal(height);
    }
};

////////////////
Solution g;

int main()
{
	
}
