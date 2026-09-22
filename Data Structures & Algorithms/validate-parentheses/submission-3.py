class Solution:
    def isValid(self, s: str) -> bool:
        openStack = []

        closedMap = {"}":"{", "]":"[", ")":"("}
        open = {"{", "[", "("}
        closed = {"]", "}", ")"}




        for i in range(len(s)):
            if(s[i] in open):
                openStack.append(s[i])
            elif(s[i] in closed):
                if(len(openStack) < 1): return False
                curr = openStack.pop()
                if(curr != closedMap[s[i]]):
                    return False
        return len(openStack) < 1


        