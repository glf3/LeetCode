#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
using namespace std;

/*Solution 1
STL The implementation of next_permutation
http://blog.csdn.net/acdreamers/article/details/8544505
*/
template<class Iterator>
bool Next_Permutation(Iterator first, Iterator last)
{
	if(first == last)
		return false;
	Iterator i = first;
	if(++i == last)
		return false;
	i = last;
	--i;
	for(;;)
	{
		Iterator t = i;
		--i;
		if(*i < *t)
		{
			Iterator j = last;
			while(!(*i <*(--j))) ;
			iter_swap(i, j);
			reverse(t, last);
			return true;
		}
		if(i == first)
			return false;
	}
}

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(!Next_Permutation(num.begin(), num.end()))
            sort(num.begin(), num.end());
    }
};

/*Solution 2*/
class Solution2{
public:
    void nextPermutation(vector<int> &num) {
        if(!next_permutation(num.begin(), num.end()))
            sort(num.begin(), num.end());
    }
};

////////////////
Solution g;

int main()
{
	vector<int> a;
	a.push_back(1), a.push_back(2), a.push_back(3), a.push_back(4), a.push_back(5);
	next_permutation(a.begin(), a.end());
	next_permutation(a.begin(), a.end());
	next_permutation(a.begin(), a.end());
	next_permutation(a.begin(), a.end());
	for(int i = 0; i < a.size(); i++)
		printf("%d ", a[i]);
	printf("\n");
	system("pause");
}
