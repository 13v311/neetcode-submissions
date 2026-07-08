class Solution {
public:
//this one is a doozy for sure. i'm still wrapping my mind around it. essentially,
//to solve this u can use the two sum II method where you have two pointers, upper and lower.
//the first loop is the starting value at each iteration, then lower and upper are used to find
//the second and third numbers of the triplet. originally, i had O(n^2) space complexity 
//because of a set of vectors, but we can realize that the fact the array is sorted by us then
//eliminates the need for us to use the same starting value more than once, which eliminates dupes

//the hardest part for me understanding this even after completing it is knowing why my solution
//confidently finds every single pair.
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> threeSums;

      sort(nums.begin(), nums.end());
     for(size_t i = 0; i < nums.size(); i++) {
      int firstNum = nums.at(i);

      //avoid choosing the same initial value twice
      if(i > 0 && nums.at(i) == nums.at(i-1)) {
        continue;
      }

      int lower = i+1;
      int upper = nums.size() - 1;
      while(lower < upper && lower != i && upper != i) {
          if(firstNum + nums.at(lower) + nums.at(upper) < 0) {
            //skip all future copies
            lower++;
            
            while(lower < upper && nums[lower] == nums[lower-1]) {lower++;}

          } else if (firstNum + nums.at(lower) + nums.at(upper) > 0) {
            //skip all future copies
            upper--;
            while(upper > lower && nums[upper] == nums[upper+1]) {upper--;}

          } else {
            int secondNum = nums.at(lower);
            int thirdNum = nums.at(upper);
            if(firstNum + secondNum + thirdNum == 0) {
              vector<int> triplet = {firstNum, secondNum, thirdNum};

              threeSums.push_back(triplet);
            }

            upper--;
            lower++;


            while(upper > lower && nums[upper] == nums[upper+1]) {upper--;}
            while(lower < upper && nums[lower] == nums[lower-1]) {lower++;}

          }


      }
     }
     return threeSums;   
    }
};
