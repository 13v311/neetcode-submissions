class Solution {
public:
    int characterReplacement(string s, int k) {
        //retry #1
        //one thing chat helped me realize is the max frequency is only important, not the character that appears the most. its only its frequency that matters
        int result = 0;

        int left = 0;
        int right = left;
        vector<int> count(26, 0);
        int maxFreq = 0;
        int distinct = 0;
        //count[s[right] - 'A']++;
        while(right < s.length() && left < s.length()) {
            count[s[right] - 'A']++;

            for(size_t i = 0; i < 26; i++) {
                maxFreq = max(maxFreq, count[i]);
            }

            int replacements = (right - left + 1) - maxFreq;
            if(replacements <= k) {
                result = max(result, right-left+1);
                right++;
                //if(right < s.length()) {count[s[right] - 'A']++;}
            } else {
                count[s[right]-'A']--;
                count[s[left] - 'A']--;
                left++;
            }                 
            maxFreq = 0;
        }

        return result;
    }
};
