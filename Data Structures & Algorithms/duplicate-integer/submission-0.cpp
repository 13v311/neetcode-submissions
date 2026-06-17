class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       std::set<int> mySet;
       for (size_t i = 0; i < nums.size(); i++) {
        if(mySet.contains(nums.at(i))) {
            return true;
        }
        mySet.insert(nums.at(i));
       }
       return false;
    }
};