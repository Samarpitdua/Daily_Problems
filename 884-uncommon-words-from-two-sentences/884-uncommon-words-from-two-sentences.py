from collections import Counter
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        di = {}
        li = s1.split(' ')
        l2 = s2.split(' ')
        li = li + (l2)
        di = dict(Counter(li))
        print(di)
        lii=[]
        for key , val in di.items():
            if val == 1:
                lii.append(key)
            
        return lii
        