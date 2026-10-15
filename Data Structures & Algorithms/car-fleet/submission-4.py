class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        #first sort in descending order to ensure clarity about the final speed of each car
        #we have to sort the indices by the values in position instead of directly sorting position and speed, since those indices are linked
        indices = list(range(len(position)))
        # [0, 1, 2]
        indices.sort(key=lambda i: position[i], reverse=True)

        finalSpeeds = []

        for i in indices:
            final = (float(target) - float(position[i])) / float(speed[i])
            if(len(finalSpeeds) == 0 or final > finalSpeeds[len(finalSpeeds)-1]):
                finalSpeeds.append(final)
                

        return len(finalSpeeds)    
        
        