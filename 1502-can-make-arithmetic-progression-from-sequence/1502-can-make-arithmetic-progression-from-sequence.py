class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        ans = arr[1] - arr[0]
        for i in range (2, len(arr)):
            diff = arr[i] - arr[i - 1]
            if diff != ans:
                return False
        return True
        