def _10to2(num):
    res = ""
    while True:
        res = res+str(num%2)
        num //= 2
        if(num == 0):
            break
    res = list(res)
    print (res)
    res = "".join(res)
    while len(res) < 32:
        res = res+str(0)
    return res
        
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        res = _10to2(n)
        return int(res, 2)

ans = Solution
print (ans.reverseBits(ans, 43261596))
