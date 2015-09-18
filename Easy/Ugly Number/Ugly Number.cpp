#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
using namespace std;

/*typedef long long int LL;

set<LL> vis;
LL a[3] = {2, 3, 5};

bool ok(int num)
{
	if(vis.count(num))
		return true;
	return false;
}

void process()
{
	vis.clear();
	priority_queue<LL, vector<LL>, greater<LL> > Q;
	vis.insert(1);
	Q.push(1);
	
	for(int i = 1; ; i++)
	{
		if(i == 2000) break;
		LL x = Q.top(); Q.pop();
		for(int j = 0; j < 3; j++)
		{
			LL b = x*a[j];
			if(!vis.count(b))
			 	{ vis.insert(b); Q.push(b); };
		}
	}
}

class Solution {
public:
    bool isUgly(int num) {
        if(ok(num))
        	return true;
        return false;
	}
	Solution()
	{
		process();
	}
};

//////////////////////
Solution g;

int main(void)
{
	if(g.isUgly(6))
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
}*/

bool ok(int num)
{
	while(num%2 == 0)
		num /= 2;
	while(num%3 == 0)
		num /= 3;
	while(num%5 == 0)
		num /= 5;
	return num == 1? true : false;
}

class Solution {
public:
    bool isUgly(int num) {
		if(num <= 0)
			return false;
        if(ok(num))
        	return true;
        return false;
	}
};

