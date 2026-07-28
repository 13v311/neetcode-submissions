class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = 0;
        unordered_map<char, int> charCounts;
        int left = 0;
        int right = 0;
        int longest = 0;
        charCounts[s[right]]++;
        while(right != s.length()) {
            //charCounts[s[right]]++;
            int windowLength = (right - left) + 1;
            //char mostFrequent; 
            int highestFrequency = 0;

            for(auto m : charCounts) {
                highestFrequency = max(highestFrequency, m.second);
            }

            if(windowLength - highestFrequency <= k) {
                longest = max(longest, windowLength);
            } else {
                charCounts[s[left]]--;
                left++;
                continue;
            }
            right++;
            charCounts[s[right]]++;
        }
        return longest;        
    }
};
