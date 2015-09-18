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

int cmp(string s1, string s2)
{
	return s1+s2 > s2+s1;
}

bool allzero(string s)
{
	for(int i = 0; i < s.length(); i++)
		if(s[i] != '0')
			return false;
	return true;
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> V;
        for(int i = 0; i < num.size(); i++)
        {
			string T;
			stringstream s;
			s << num[i]; s >> T;
			V.push_back(T);
		}
        sort(V.begin(), V.end(), cmp);
        string ans = "";
        for(int i = 0; i < V.size(); i++)
        	ans += V[i];
        if(allzero(ans))
        	return "0";
        return ans;
    }
};

///////////////////////
Solution g;

int main(void)
{
	vector<int> num;
	num.push_back(3); num.push_back(30); num.push_back(34); num.push_back(5); num.push_back(9);
	cout << g.largestNumber(num) << endl;
	system("pause");
}
