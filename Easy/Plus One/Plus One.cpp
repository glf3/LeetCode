#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		vector<int> ans;
		for(int i = 0; i < digits.size(); i++)
			ans.push_back(digits[i]);
		
		reverse(ans.begin(), ans.end());
		ans[0] += 1;
		int c = 0;
		for(int i = 0; i < ans.size(); i++)
		{
			int tmp = ans[i]+c;
			ans[i] = (tmp)%10;
			c = tmp / 10;
		}
		if(c) ans.push_back(c);
		reverse(ans.begin(), ans.end());
		return ans;
    }
};

/////////////

Solution g;

int main()
{
	vector<int> digit;
	digit.push_back(99);
	vector<int> ans = g.plusOne(digit);
	for(int i = 0; i < ans.size(); i++)
		printf("%d", ans[i]);
	printf("\n");
	system("pause");
	return 0;
}
