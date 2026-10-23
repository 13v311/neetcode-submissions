class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        triplets = set()
        for i in range(len(nums)):
            initial = nums[i]
            left = i+1
            right = len(nums) - 1
            if(i >= len(nums) - 2): break
            while(left < right):
                if(initial + nums[left] + nums[right] == 0):
                    triplets.add(tuple([initial, nums[left], nums[right]]))
                    left += 1
                elif(initial + nums[left] + nums[right] > 0):
                    right -= 1
                else:
                    left += 1
        
        results = []
        for t in triplets:
            results.append(list(t))
        return results
        