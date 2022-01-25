class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        n = len(arr)
        q = 0
        r = 0
        ct = 0
        ans = 0
        for i in range (1 , n):
            if arr[i] == arr[i - 1]:
                r = 0
                q = 0
            elif arr[i] > arr[i - 1] and r != 0:
                r = 0
                q = 2
            elif arr[i] > arr[i - 1] and r == 0 and q > 0:
                r = 0
                q += 1
            elif arr[i] > arr[i - 1] and r == 0:
                r = 0
                q = 2
            elif arr[i] < arr[i - 1] and q > 0:
                r += 1
            elif arr[i] < arr[i - 1] and q == 0:
                r = 0
            if r > 0 and q > 0:
                ans = max(ans , r + q)
#             print(ct , end = " ")
#             print(r , end = " ")
            
#             print(q)
        return ans
        