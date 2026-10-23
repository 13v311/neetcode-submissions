class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        triplets = []
        for i in range(len(nums)):
            initial = nums[i]
            left = i+1
            right = len(nums) - 1
            if(i >= len(nums) - 2): break
            if(i > 0 and nums[i] == nums[i-1]): continue
            while(left < right):
                if(initial + nums[left] + nums[right] == 0):
                    triplets.append([initial, nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while(left < right and nums[left] == nums[left-1]): left += 1
                    while(right > left and nums[right] == nums[right+1]): right -= 1
                elif(initial + nums[left] + nums[right] > 0):
                    right -= 1
                else:
                    left += 1
        

        return triplets
        