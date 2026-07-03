class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> chars;
        size_t i = 0;

        //we actually have to clean the string first because it has weird behavior otherwise
        string cleaned;

        for(size_t j = 0; j < s.length(); j++) {
          if(isdigit(s[j]) || isalpha(s[j])) {
            cleaned += tolower(s[j]); 
          }

        }

        for(i; i < cleaned.length() / 2; i++) {
          chars.push(cleaned[i]);
        }
        

        if(cleaned.length() % 2 != 0) {i++;}
        for(i; i< cleaned.length(); i++) {
          if(chars.top() != cleaned[i]) {return false;} else {chars.pop();}
        }
        
        return chars.empty();

    }
};
