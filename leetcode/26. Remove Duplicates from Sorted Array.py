class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        temp = None
        i = 0
        for num in nums:
            if num == temp:                
                continue                              
            temp = num
            nums[i] = num
            i+=1
        return i    
