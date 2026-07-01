class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //we will do the prefix suffix method provided in hints. in this we
        //multiply all the numbers to the left of the current index together for each prefix,
        //and multiply all the numbers to the right of the current index together for each suffix
        //then at the end we will multiply each prefix and suffix index together for each product
        vector<int> prefix;
        vector<int> suffix;
        vector<int> products;
        int product = 1;
        for(size_t i = 0; i < nums.size(); i++) {
            if(i == 0) {
                prefix.push_back(product);
                continue;
            }
            product *= nums[i-1];
            prefix.push_back(product);
        }
        product = 1;
        
        for(int i = nums.size()-1; i >= 0; i--) {
            if(i == nums.size()-1) {
                suffix.push_back(product);
                continue;
            }
            product *= nums[i+1];
            suffix.push_back(product);
        }
        //suffix must be reversed to match the prefix indexes
        //i.e., the first index of suffix will be the numbers multiplied together
        //to the right of the number at the first index of prefix in nums
        std::reverse(suffix.begin(), suffix.end());
        
        for(size_t i = 0; i < nums.size(); i++) {
            products.push_back(suffix[i] * prefix[i]);
        }
        return products;
    }
};
