class Solution {
public:
//this is called floyd's cycle detection. it's for finding dupes when there is one number that is duped (u must know ahead of time that a dupe exists otherwise i think there will be an inf loop)
    int findDuplicate(vector<int>& nums) {
        int slow = nums[slow];
        int fast = nums[nums[fast]];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
        
    }
};
