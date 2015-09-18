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

void init(string &path)
{
	string s = "";
	s += path[0];
	for(int i = 1; i < path.size(); i++)
		if(path[i] == path[i-1] && path[i] == '/')
			continue;
		else
			s += path[i];
	path = s;
}

string process(string &path)
{
	init(path);
	int pre = 0;
	stack<string> S;
	int sz = path.size();
	if(path[sz-1] == '/')
	{
		for(;;)
		{
			int nextpos = path.find('/', pre+1);
			if(nextpos == string::npos) break;
			string tmp = path.substr(pre+1, nextpos-pre-1);
			pre = nextpos;
			if(tmp == ".") ;
			else if(tmp == "..")
			{
				if(!S.empty())
					S.pop();
			}
			else S.push(tmp);
		}
	}
	else
	{
		for(;;)
		{
			int nextpos = path.find('/', pre+1);
			string tmp = path.substr(pre+1, nextpos-pre-1);
			if(nextpos == string::npos)
				tmp = path.substr(pre+1);
			pre = nextpos;
			if(tmp == ".") ;
			else if(tmp == "..")
			{
				if(!S.empty())
					S.pop();
			}
			else S.push(tmp);
			if(nextpos == string::npos)
				break;
		}	
	}
	string s = "";
	if(S.empty())
		{ s += "/"; return s;}
	else
	{
		vector<string> a;
		while(!S.empty())
			{ a.push_back(S.top()); S.pop(); }
		for(int i = a.size()-1; i >= 0; i--)
			s += "/" + a[i];
	}
	return s;
}

class Solution {
public:
    string simplifyPath(string path) {
		return process(path);
    }
};

////////////////
Solution g;

int main()
{
	//string path = "/home//foo/";
	//string path = "/a/./b/../../c/";
	string path = "/...";
	init(path);
	
	cout << path << endl;
	path = g.simplifyPath(path);
	cout << path << endl;
	system("pause");
}
