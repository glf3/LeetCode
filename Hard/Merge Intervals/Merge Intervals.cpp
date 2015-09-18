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

vector<Interval> process(vector<Interval> &intervals)
{
	vector<Interval> b;
	vector<Interval> &a = intervals;
	if(!a.size())
		return b;
	sort(a.begin(), a.end(), cmp);
	a.push_back(Interval(INF, INF));
	int L = a[0].start, R = a[0].end;
	for(int i = 1; i < a.size(); i++)
	{
		if(a[i].start > R)
		{
			b.push_back(Interval(L, R));
			L = a[i].start, R = a[i].end;
		}
		else if(a[i].start <= R && a[i].end >= R)
			R = a[i].end;
	}
	return b;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        return process(intervals);
    }
};

///////////////////
Solution g;

int main()
{
	vector<Interval> a, b;
	a.push_back(Interval(1, 3)); a.push_back(Interval(2, 6));
	a.push_back(Interval(8, 10)); a.push_back(Interval(15, 18));
	b = g.merge(a);
	for(int i = 0; i < b.size(); i++)
	{
		printf("%d %d\n", b[i].start, b[i].end);
	}
	system("pause");
}
