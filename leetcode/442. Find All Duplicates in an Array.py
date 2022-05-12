class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ls = [0,]*(len(nums)+1)
        res = []
        for i in nums:
            if ls[i]==1:
                res.append(i)
            else:
                ls[i] = 1
        return res
