class Solution {
public:
    bool isAnagram(string s, string t) {
       if (s.length() != t.length()) return false;
       std::map<char, int> letterCounts;
       for(size_t i = 0; i < s.length(); i++) {
        if(letterCounts.contains(s[i])) {
            letterCounts[s[i]]++;
        } else {
            letterCounts[s[i]] = 1;
        }
       }

       for(size_t i = 0; i < t.length(); i++) {
        if(!letterCounts.contains(t[i]) || letterCounts[t[i]] < 1) {
            return false;
        }
        letterCounts[t[i]]--;
       } 
       return true;
    }
};
