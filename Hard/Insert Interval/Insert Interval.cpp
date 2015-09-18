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

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

const int INF = 0x3f3f3f3f;
bool cmp(const Interval &a, const Interval &b)
{
	if(a.start != b.start)
	return a.start < b.start;
	else return a.end < b.end;
}

vector<Interval> process(vector<Interval> &a)
{
	vector<Interval> ans;
	sort(a.begin(), a.end(), cmp);
    int L = a[0].start, R = a[0].end;
    a.push_back(Interval(INF, INF));
    for(int i = 1; i < a.size(); i++)
    {
		if(a[i].start > R)
		{
			ans.push_back(Interval(L, R));
			L = a[i].start, R = a[i].end;
		}
		else if(a[i].start <= R && a[i].end >= R)
			R = a[i].end;
	}
	return ans;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> &a = intervals;
        a.push_back(newInterval);
    	vector<Interval> ans;
    	ans = process(a);
    	return ans;
    }
};

//////////////
Solution g;

int main()
{
	vector<Interval> a;
	a.push_back(Interval(1, 2)); a.push_back(Interval(3, 5));
	a.push_back(Interval(6, 7)); a.push_back(Interval(8, 10));
	a.push_back(Interval(12, 16));
	vector<Interval> b = g.insert(a, Interval(4, 9));
	for(int i = 0; i < b.size(); i++)
	{
		printf("%d %d\n", b[i].start, b[i].end);                                               
	}
	system("pause");
}
