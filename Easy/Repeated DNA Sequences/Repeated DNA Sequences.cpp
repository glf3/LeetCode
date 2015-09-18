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

vector<string> process(string s)
{
	vector<string> ans;
	if(s.length() <= 10)
		return ans;
	int n = s.length();
	set<string> vis;
	for(int i = 0; i < n-10; i++)
	{
		string tmp = s.substr(i, 10);
		if(vis.count(tmp))
			ans.push_back(tmp);
		else
			vis.insert(tmp);
	}
	return ans;
}

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        return process(s);
    }
};

//////////////////////////
Solution g;

int main(void)
{
	vector<string> t = g.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	for(int i = 0; i < t.size(); i++)
		cout << t[i] << endl;
	system("pause");
	return 0;
}
