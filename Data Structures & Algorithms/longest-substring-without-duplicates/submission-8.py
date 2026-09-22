class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        right = 0
        maxLength = 0
        seen = set()
        while right < len(s):
            if(s[right] in seen):
                seen.remove(s[left])
                left += 1
            else:
                seen.add(s[right])
                maxLength = max(maxLength, right - left + 1)
                right += 1

        return maxLength

