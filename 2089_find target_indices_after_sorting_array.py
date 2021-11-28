class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        li=[]
        nums.sort()
        for i in range (0,len(nums)):
            if nums[i] == target:
                li.append(i)
        return li
        
