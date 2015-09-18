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

typedef set<int> Set;
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        Set vis; vis.insert(elem);
        vector<int> ans;
        for(int i = 0; i < n; i++)
        	if(!vis.count(A[i])) ans.push_back(A[i]);
        for(int i = 0; i < ans.size(); i++)
        	A[i] = ans[i];
        return ans.size();
    }
};

////////
Solution g;

int main()
{
	int A[10] = {4, 5};
	int elem = 5;
	printf("%d\n", g.removeElement(A, 2, 5));
	system("pause");
}
