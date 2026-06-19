#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //int total = target;
        //int index1; int index2;
        vector<int> results;
        std::unordered_map<int, vector<int>> sums;
        for(size_t i = 0; i < nums.size(); i++) {
            sums[nums[i]].push_back(i);
            if(i > 0) {
                if(sums.find(target - nums[i]) != sums.end() && (sums.at(target - nums[i])).at(0) != i) {
                    if(nums[i] == target - nums[i]) {
                        results.push_back(sums.at(target - nums[i]).at(0));
                        results.push_back(sums.at(target - nums[i]).at(1));
                    } else {
                        results.push_back(sums.at(target - nums[i]).at(0));
                        results.push_back(sums.at(nums[i]).at(0));
                    }
                    return results;
                }
            }
        }
        return results;
    }
};
