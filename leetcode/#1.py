"""
暴力解法:
"""
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for index in range(0, len(nums)):
            for other in range(index+1, len(nums)):
                if nums[index] + nums[other] == target:
                    return [index, other]