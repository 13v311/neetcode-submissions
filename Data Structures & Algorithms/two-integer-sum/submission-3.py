class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        charToIndex = {}
        result: List[int] = []
        index = 0
        for num in nums:
            charToIndex[num] = index
            index += 1

        for i in range(len(nums)):
            if charToIndex.get(target - nums[i]):
                result1 = charToIndex.get(target - nums[i])
                result2 = i
                if(result2 < result1):
                    return [result2, result1]
                elif (result2 > result1):
                    return [result1, result2]

        

