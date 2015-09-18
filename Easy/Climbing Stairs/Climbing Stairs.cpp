#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
using namespace std;

int table[50] = {0};
int cal(int n)
{
	if(n == 1) return (table[n] = 1);
	if(n == 2) return (table[n] = 2);
	if(table[n]) return table[n];
	else return (table[n] = cal(n-1)+cal(n-2));
}

class Solution {
public:
    int climbStairs(int n) {
		return cal(n);
    }
};

////////
Solution g;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		printf("%d\n", g.climbStairs(n));
	}
	return 0;
}
