#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

typedef map<int, int> Map;
const int maxn = 1010;
bool vis[maxn];

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int ans = 0, n = s.length();
		memset(vis, 0, sizeof(vis));
		for(int p1 = 0, p2 = 0; p2 < n; p2++)
		{
			while(vis[s[p2]])
			{
				vis[s[p1]] = 0;
				p1++;
			}
			ans = max(ans, p2-p1+1);
			vis[s[p2]] = 1;
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
