#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

int process(vector<int> &a)
{
	if(a.size() == 0)
		return 0;
	if(a.size() == 1)
	{
		if(a[0] != 0)
			return 1;
		else
			return 0;
	}
	sort(a.begin(), a.end());
	int n = a.size();
	vector<int> b(n+10), c(n+10);
	b.push_back(-1); c.push_back(-1);
	for(int i = 0; i < n; i++)
	{
		int sum = 0;
		for(int j = 0; j < n; j++)
			if(a[j] >= i+1) sum++;
		b[i+1] = sum;
	}
	int w = a[0];
	for(int i = 0; i < n; i++)
		{ w = max(w, a[0]); c[i+1] = w; }
	for(int i = n; i >= 1; i--)
	{
		if(c[n-b[i]] <= i && b[i] >= i)
			return i;
	}
	return 0;
}

class Solution {
public:
    int hIndex(vector<int>& citations) {
        return process(citations);
    }
};

////////////////////
Solution g;

int main(void)
{
	vector<int> a;
	/*a.push_back(3); a.push_back(0); a.push_back(6);
	a.push_back(1); a.push_back(5);*/
	a.push_back(11); a.push_back(15);
	printf("%d\n", g.hIndex(a));
	system("pause");
	return 0;
}
