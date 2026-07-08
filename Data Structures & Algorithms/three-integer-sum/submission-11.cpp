class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> threeSums;
      set<vector<int>> uniqueTriplets;
      sort(nums.begin(), nums.end());
     for(size_t i = 0; i < nums.size(); i++) {
      int firstNum = nums.at(i);

      int lower = i+1;
      int upper = nums.size() - 1;
      while(upper != lower && lower != i && upper != i && upper < nums.size() && lower < nums.size()) {
          /*if(j+1 >= nums.size()) {break;}
          int secondNum = nums.at(j);
          int thirdNum = nums.at(j+1 % nums.size());*/

          if(firstNum + nums.at(lower) + nums.at(upper) < 0) {
            lower++;
          } else if (firstNum + nums.at(lower) + nums.at(upper) > 0) {
            upper--;
          } else {
            int secondNum = nums.at(lower);
            int thirdNum = nums.at(upper);
            if(firstNum + secondNum + thirdNum == 0) {
              vector<int> triplet = {firstNum, secondNum, thirdNum};
              sort(triplet.begin(), triplet.end());

              

              if(!uniqueTriplets.contains(triplet)) {
                threeSums.push_back(triplet);
                uniqueTriplets.insert(triplet);
              }
            }
            upper--;
            lower++;

          }


      }
     }
     return threeSums;   
    }
};
