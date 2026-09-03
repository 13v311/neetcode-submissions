class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s) != len(t)):
            return False;
        
        counts = {}
        compared = {}
        for c in s:
            counts[c] = counts.get(c, 0) + 1
        
        for c in t:
            compared[c] = compared.get(c, 0) + 1

        for letter in counts:
            if compared.get(letter, 0) == 0 or counts[letter] != compared[letter]:
                return False
        return True
