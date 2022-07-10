# recursive approach using hashmapping concept (won't work as per the constraints)
class Solution:

    def findDuplicate(self, nums):

        def store(nums, cur):
            if cur == nums[cur]:
                return cur
            nxt = nums[cur]
            nums[cur] = cur
            return store(nums, nxt)

        return store(nums, 0)


# iterative approach
class Solution:

    def findDuplicate(self, nums: List[int]) -> int:
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                if nums[i] == nums[j]:
                    return nums[i]
