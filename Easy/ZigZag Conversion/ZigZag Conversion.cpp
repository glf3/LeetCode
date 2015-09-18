#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
using namespace std;

string process(string s, int m)
{
	int n = s.length();
	if(!n) return s;
	if(m <= 1) return s;
	if(m >= n) return s;
	
	string t = "";
	int step = (m-1)*2;
	for(int i = 0; i < n; i += step)
		t += s[i];
	for(int i = 1; i < m-1; i++)
	{
		for(int k = 0, j = i; j < n; k++)
		{
			t += s[j];
			if(k & 1)
				j += i*2;
			else
				j += (step-2*i);
		}
	}
	for(int i = m-1; i < n; i += step)
		t += s[i];
	return t;
}

class Solution {
public:
    string convert(string s, int nRows) {
        return process(s, nRows);
    }
};

//////////////
Solution g;

int main()
{
	cout << g.convert("PAYPALISHIRING", 3) << endl;
	cout << g.convert("abcde", 4) << endl;
	system("pause");
	return 0;
}
