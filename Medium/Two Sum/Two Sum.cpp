typedef map<int, int> Map;
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        int sz = numbers.size();
        Map g;
        int ok = 0;
        for(int i = 0; i < numbers.size(); i++)
        {
            int x = target-numbers[i];
            if(g.count(numbers[i]))
            {
                ans.push_back(g[numbers[i]]+1);
                ans.push_back(i+1);
                ok = 1; break;
            }
            else g[x] = i;
        }
        assert(ok >= 1);
        return ans;
    }
};
