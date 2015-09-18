def _10to2(num):
    res = ""
    while True:
        res = res+str(num%2)
        num //= 2
        if(num == 0):
            break
    res = list(res)
    res.reverse()
    res = "".join(res)
    return res

class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        x = int(a, 2)
        y = int(b, 2)
        z = (x+y)
        return _10to2(z)
