class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        allnum = nums1 + nums2
        allnum.sort()

        mid = 0
        mid_t = 0
        length = len(allnum)
        if length % 2 != 0:
            mid = length // 2

            return allnum[mid]
        else:
            mid = length // 2 - 1
            mid_t = mid+1
            
            return (allnum[mid] + allnum[mid_t]) / 2
