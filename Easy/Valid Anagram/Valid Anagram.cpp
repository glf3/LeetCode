#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		if(s == "" && t == "")
			return true;
		if(s.length() != t.length())
			return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t? true : false;
    }
};

////////////////////
Solution g;

int main(void)
{
	if(g.isAnagram("anagram", "nagaram"))
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
}
