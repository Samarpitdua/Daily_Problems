class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        ct = 0
        for i in range (1 , 100000):
            if i not in arr:
                ct += 1
            if k == ct:
                return i
        return -1