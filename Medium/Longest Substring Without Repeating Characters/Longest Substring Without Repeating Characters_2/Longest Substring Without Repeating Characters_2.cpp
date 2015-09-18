#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

const int maxn = 1010;
int vis[maxn];

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        memset(vis, -1, sizeof(vis));
        int ans = 0, res = 0, pre = 0;
		for(int i = 0; i < n; i++)
		{
			int c = s[i];
			if(vis[c] == -1)
			{
				res++;
				vis[c] = i;
			}
			else if(vis[c] != -1)
			{
				ans = max(ans, res);
				res = i-vis[c];
				int t = vis[c];
				for(int k = pre; k < vis[c]; k++) vis[s[k]] = -1;
				pre = t+1;
				vis[c] = i;
			}
        }
        return ans;
    }
};

///////////////////
Solution g;

int main()
{
	//string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	string s = "qopubjguxhxdipfzwswybgfylqvjzhar";
	//string s = "abceeedd";
	printf("%d\n", g.lengthOfLongestSubstring(s));
	system("pause");
}
