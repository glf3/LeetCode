class Solution:
    # @param {integer} numerator
    # @param {integer} denominator
    # @return {string}
    def fractionToDecimal(self, numerator, denominator):
        a = numerator
        b = denominator
        if (a == 0):
            return str(0)
        ans = ""
        if (a < 0 or b < 0) and not(a < 0 and b < 0):
            ans += "-"
        a = abs(a)
        b = abs(b)
        if (a%b == 0):
            ans += str(a//b)
            return ans
        else:
            ans += str(a//b)
            ans += "."
            r = a%b;
            mp = {}
            while r:
                if r in mp:
                    ans = ans[:mp[r]]+"("+ans[mp[r]:]+")"
                    return ans
                else:
                    mp[r] = len(ans)
                    r = r*10
                    ans += str(r//b)
                    r %= b
            return ans

ans = Solution
print (ans.fractionToDecimal(ans, 0, -5))
