#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

/*Solution 1*/
class Solution {
public:
    int strStr(char *haystack, char *needle) {
		int n = strlen(haystack), m = strlen(needle);
		if(n < m) return -1;
		if(n == 0 || m == 0) return 0;
		for(int i = 0; i <= n-m; i++)
		{
			int j;
			for(j = 0; j < m && i+j < n; j++)
				if(haystack[i+j] != needle[j]) break;
			if(j >= m) return i;
		}
		return -1;
    }
};

/*Solution 2*/
class Solution2{
public:
    int strStr(char *haystack, char *needle) {
        char * p = strstr(haystack, needle);
        if(p == NULL) return -1;
        else return int(p - haystack);
    }
};

/////////
Solution g;

int main()
{
	char s[110], t[110];
	while(scanf("%s%s", s, t))
	{
		printf("%d\n", g.strStr(s, t));
	}
	return 0;
}
