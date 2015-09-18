def BSearch(n):
    if (n == 0):
        return 0
    x = 1; y = n
    ans = -1
    while (x <= y):
        mid = x+((y-x)//2)
        if mid*mid <= n:
            ans = mid
            x = mid+1
        else:
            y = mid-1
    return ans

class Solution:
    # @param x, an integer
    # @return an integer
    def sqrt(self, x):
        return BSearch(x)

g = Solution
x = int(input("Interger:"))
print(g.sqrt(g, x))
