class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        sumarr = []
        sum_num = 0
        for num in nums:
            sum_num += num
            sumarr.append(sum_num)
        
        ind = len(nums) - 1
        
        while ind >= 2:
            if nums[ind] < sumarr[ind-1]:
                return nums[ind] + sumarr[ind-1]
            ind -= 1
        return -1