table = {}
def dp(i, j, n, m):
    x = i*m+j
    if x in table:
        return table[x]
    elif i == n-1 and j == m-1:
        table[x] = 1
        return 1
    elif i == n-1:
        table[x] = dp(i, j+1, n, m)
        return table[x]
    elif j == m-1:
        table[x] = dp(i+1, j, n, m)
        return table[x]
    else:
        table[x] = dp(i+1, j, n, m) + dp(i, j+1, n, m)
        return table[x]

def cal (n, m):
    return dp(0, 0, n, m)

class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
        table.clear()
        return cal(n, m)

ans = Solution
print (ans.uniquePaths(ans, 2, 2))
