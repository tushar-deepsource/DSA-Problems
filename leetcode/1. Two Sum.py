class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n-1):
            other_num = target-nums[i]
            if other_num in nums[i+1:]:
                nums.pop(i)
                return [i,nums.index(other_num)+1]
