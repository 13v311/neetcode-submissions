//sliding window is a rlly simple concept yet works so well!
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int left = 0; 
       int right = left + s1.length() - 1;

       //we will implement buckets which we sawm mentioned in another problem long ago
       //we can do it this way since its only lowercase letters
       vector<int> freq(26, 0); //makes 26 spots each initialized with 0
        for(char c : s1) {
            freq[c - 'a']++;
        }

       /*unordered_map<char, int> charCounts;
       for(size_t i = 0; i < s1.length(); i++) {
            charCounts[s1[i]]++;
       }*/

       while(right != s2.length()) {
            //unordered_map<char, int> charDupe = charCounts;
            vector<int> windowFreq(26, 0);
            for(size_t i = left; i <= right; i++) {
                windowFreq[s2[i] - 'a']++;
            }

            //we are seeing if both the window and s1 have the same charCounts
            if(windowFreq == freq) {
                return true;
            }
            left++;
            right++;
       } 
       return false;
    }
};
