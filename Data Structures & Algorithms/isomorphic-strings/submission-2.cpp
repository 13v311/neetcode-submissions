class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //my initial thoughts are to map the characters to the counts, then another map to map s to t
        /*map<char, int> charCountsS;
        map<char, int> charCountsT;
        map<char, char> charReplaced;

        for(size_t i = 0; i < s.length(); i++) {
            charCountsS[s[i]] += 1;
        }

        for(size_t i = 0; i < t.length(); i++) {
            charCountsT[t[i]] += 1;
        }

        cout << charCountsS.size();
        cout << charCountsT.size();

        //we immediately know if the sizes of the two maps are unequal that means one map has too many letters that cannot be replaced 1-1
        if(charCountsS.size() != charCountsT.size()) {return false;}

        //now i need to map each char to a new char given they're the same size map
        //im not sure how to do this very efficiently tho*/

        //i later realized that some strings can have the same char counts but not be isomorphic, so i then thought it would make more sense to map each char to the corresponding char in a string and if we ever see that char again, it needs to match that original mapping we have established. this would also be much faster O(N) than what i was trying to do

        unordered_map<char, char> m;
        if(s.length() != t.length()) {return 0;}

        for(size_t i = 0; i < s.length(); i++) {
            if(m.empty() || m.count(s[i]) < 1)  {
                m[s[i]] = t[i];
            } else {
                if(t[i] != m[s[i]]) {return false;}
            }
        }
        //we have to now make the map doing the same but with t because apparently this single check is not enough for something like abbAB -> ABBAa

        unordered_map<char, char> m2;
        for(size_t i = 0; i < t.length(); i++) {
            if(m2.empty() || m2.count(t[i]) < 1)  {
                m2[t[i]] = s[i];
            } else {
                if(s[i] != m2[t[i]]) {return false;}
            }
        }

        return true;
    }
};