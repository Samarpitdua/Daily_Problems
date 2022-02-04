class Solution:
    def minOperations(self, st: str) -> int:
        ct = 0
        s = list(st)
        for i in range (1 , len(s)):
            if s[i] == '1':
                if s[i - 1] == s[i] :
                    ct += 1
                    s[i] = '0'
            else:
                if s[i - 1] == s[i] :
                    ct += 1
                    s[i] = '1'
        return min(len(s) - ct , ct)