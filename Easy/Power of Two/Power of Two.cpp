#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
		int sum = 0;
		if(n < 0) return false;
        while(n)
        {
			n &= n-1;
			sum++;
		}
		return sum == 1? true : false;
    }
};

///////////////////
Solution g;

int main(void)
{
	g.isPowerOfTwo(69);
	system("pause");
}
