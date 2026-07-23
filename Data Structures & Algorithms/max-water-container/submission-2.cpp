//we can use the two pointer method again, where one is at the end and one at the beginning
//we can get area based on the length between two pointers and the smallest height out of the two
//so we keep calculating area at each point to see if we can ever get a bigger area until pts are equal
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int p1 = 0;
        int p2 = heights.size() - 1;
        int maxArea = 0;
       while(p1 != p2) {
           int currArea = (p2 - p1) * min(heights[p2], heights[p1]);
           if(currArea > maxArea) {
            maxArea = currArea;
           }

           if(heights[p1] < heights[p2]) {
            p1++;
           } else {
            p2--;
           }
       }
       return maxArea; 
    }
};
