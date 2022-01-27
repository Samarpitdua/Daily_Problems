class Solution:
    def reverseVowels(self, s: str) -> str:
        li = list(s)
        l = 0
        r = len(li) - 1
        vowels = ("aeiouAEIOU")
        while l < r :
            if li[l] in vowels and li[r] in vowels:
                li[l] , li[r] = li[r] , li[l]
                l += 1
                r -= 1
            elif li[l] in vowels:
                r -= 1
            elif li[r] in vowels:
                l += 1
            else:
                l += 1
                r -= 1
        return ''.join(li)
            
        