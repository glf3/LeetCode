#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int flag = 0;
        if(x < 0) { flag = 1; x *= -1; }
        string s; stringstream ss;
        ss << x;
        ss >> s;
        std::reverse(s.begin(), s.end());
        int num = 0;
        for(int i = 0; i < s.length(); i++)
        	num = num*10 + s[i]-'0';
        return flag? -num : num;
    }
};

///////////////////
Solution g;

int main()
{
	int x = g.reverse(-12345);
	printf("%d\n", x);
	system("pause");
}
