def abs (x):
    if(x < 0):
        x *= -1
    return x

def cal (x, y):
    neg1 = neg2 = 0
    if x < 0:
        neg1 = 1
    if y < 0:
        neg2 = 1
    x = abs(x)
    y = abs(y)
    if x < y:
        return 0
    res = int(x/y)
    if neg1 != 0 and neg2 != 0:
        return res
    elif (neg1 == 0 and neg2 == 0):
        return res
    else:
        return -res

ceil = lambda x:int(x)+1

#from math import ceil
class Solution:
    # @return an integer
    def divide(self, dividend, divisor):
        return cal(dividend, divisor)

ans = Solution
print (ans.divide(ans, -1, 1))
