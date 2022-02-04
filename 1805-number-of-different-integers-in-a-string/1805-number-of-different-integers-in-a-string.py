class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        t = ""
        set1 = set()
        for i in word :
            if i >= 'a' and i <= 'z' :
                if t != "":
                    set1.add(int(t))
                    t = ""
            else:
                t += i
        if t!= "":
            set1.add(int(t))
        return len(set1)
        