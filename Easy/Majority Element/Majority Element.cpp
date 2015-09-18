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

typedef pair<int, int> PII;
typedef map<int, int>::iterator Iterator;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int, int> mp;
        int n = num.size();
        for(int i = 0; i < num.size(); i++)
        	if(mp.count(num[i]) != 0)
        		mp[num[i]]++;
        	else
        		mp[num[i]] = 1;
        for(Iterator it = mp.begin(); it != mp.end(); it++)
        	if(it->second > n/2)
        		return it->first;
    }
};

////////////
Solution g;

int main(void)
{
	vector<int> num;
	num.push_back(1), num.push_back(2), num.push_back(3), num.push_back(1), num.push_back(1);
	printf("%d\n", g.majorityElement(num));
	system("pause");
}
