class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        di = dict(Counter(nums))
        while True:
            if original in di.keys() :
                original *= 2
            else:
                break
        return original
        