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
    int findMin(vector<int> &num) {
		vector<int> &a = num;
		int x = 0, y = a.size()-1;
		while(a[x] > a[y])
		{
			int mid = x+(y-x)/2;
			if(a[mid] >= a[x])
				x = mid+1;
			else
				y = mid;
		}
		return a[x];
    }
};

/////////////////////
Solution g;

int main()
{
	vector<int> a;
	a.push_back(100); a.push_back(101); a.push_back(102); a.push_back(13); 
	a.push_back(14); a.push_back(19); a.push_back(21);
	printf("%d\n", g.findMin(a));
	system("pause");
	return 0;
}
