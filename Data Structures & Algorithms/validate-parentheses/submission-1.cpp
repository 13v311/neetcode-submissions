//using unordered set for o(1) lookups
//implement a stack! reminds me of cs301
class Solution {
public:
    bool isValid(string s) {
        unordered_set<char> openP = {'{', '(', '['};
        unordered_set<char> closedP = {')', '}', ']'};
        unordered_map<char, char> parenthesesPairs = {
            {'{','}'},
            {'(',')'},
            {'[',']'},
        };

        vector<char> parenthesesStack;

        for(size_t i = 0; i < s.length(); i++) {
            if(openP.contains(s[i])) {
                parenthesesStack.push_back(s[i]);
            } else if(closedP.contains(s[i])) {
                if(parenthesesStack.size() > 0) {
                    char p = parenthesesStack.back();
                    parenthesesStack.pop_back();
                    if(s[i] != parenthesesPairs[p]) {
                        return false;
                    }
                } else {return false;}
            } else {return false;}
        }

        //dont forget to check parentheses stack at the end ensuring
        //we got all of the open brackets matched to a closed bracket
        if(parenthesesStack.size() > 0) {return false;}
        return true;
    }
};
