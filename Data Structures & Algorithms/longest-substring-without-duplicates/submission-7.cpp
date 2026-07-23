//originally my method was not sliding window, a new technique that im learning here
//my method would start the entire string over if a dupe was found instead of simply 
//changing the window of letters we were looking at; we have two pointers and the range of them
//represents the substring aka window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int longest = 0;
        int left = 0; 
        int right = 0;
        set<char> uniqueChars;

        while(right != s.length()) {
            if(!uniqueChars.contains(s[right])) {
                uniqueChars.insert(s[right]);
                length = (right - left) + 1;
                right++;

                if(length > longest) {
                    longest = length;
                }

            } else {
                //if we find a dupe, we should just change the window by moving the left ptr
                uniqueChars.erase(s[left]);
                left++;
                length = (right - left) + 1;
            }
        }
        return longest;
    }
};
