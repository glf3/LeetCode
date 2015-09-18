#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <sstream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
    	string s1, t = "";
    	for(int i = 0; i < strlen(s); i++)
    		t += s[i];
    	stringstream ss(t);
    	int sz = 0;
    	while(ss >> s1) sz++;
    	return sz? s1.length() : 0;
    }
};

///////////////////
Solution g;

int main()
{
	printf("%d %d\n", g.lengthOfLastWord("Hello world"), g.lengthOfLastWord("   "));
	system("pause");
}
