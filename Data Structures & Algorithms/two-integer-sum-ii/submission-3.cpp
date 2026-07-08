class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        //we will do the two pointers method, basically each time the result of our two pointers
        //is too high, we will move the upper pointer down, and if the result is too low, we
        //will move the lower pointer up! honestly makes so much sense

        //this is different than two sum because we get a sorted array and the expected
        //memory usage is less at O(1)
        /*
        this would allow u to use iterators but that is less clear
        int* lower = new int*;
        int* upper = new int*; 

        lower = numbers.begin();
        upper = numbers.end();

        int leftInd = lower - numbers.begin();
        int rightInd = upper - numbers.end();
        */

        int lower = 0;
        int upper = numbers.size() - 1;

        while(lower < numbers.size() && upper < numbers.size() && numbers.at(lower) + numbers.at(upper) != target) {
          if(target < numbers.at(lower) + numbers.at(upper)) {
            upper--;
          } else {
            lower++;
          }
        }

        result.push_back(lower+1);
        result.push_back(upper+1);
        return result;
    }
};
