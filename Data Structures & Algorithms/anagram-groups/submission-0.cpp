class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams; //all anagram groups
        vector<std::map<char, int>> groupChars; //represents the char counts for every anagram group
        if(strs.size() < 1) {
            return anagrams;
        } else if (strs.size() < 2) {
            anagrams.push_back(strs);
            return anagrams;
        } else {
            for(size_t i = 0; i < strs.size(); i++) {
                std::map<char, int> charCounts;
                //im going to make the map for the amount of chars in 
                //the current string, but i wont immediately add it to
                //my vector of maps
                for(size_t j = 0; j < strs.at(i).length(); j++) {
                    charCounts[strs.at(i)[j]]++;
                }

                //special case for very first string
                if(i == 0) {
                    vector<string> group;
                    group.push_back(strs.at(0));
                    anagrams.push_back(group);
                    groupChars.push_back(charCounts);
                    continue;
                } else { 
                    bool added = false;
                    //if the map for the current string already exists in groupChars, 
                    //that means one of our anagram groups already matches this string
                    
                    for(size_t j = 0; j < groupChars.size(); j++) {
                        if(groupChars.at(j) == charCounts) {
                            anagrams.at(j).push_back(strs.at(i));
                            added = true;
                            break;
                        }
                    }
                    //we will make a new group for this string since it doesnt match
                    if(!added) {
                        groupChars.push_back(charCounts);
                        vector<string> group;
                        group.push_back(strs.at(i));
                        anagrams.push_back(group);
                    }
                }
            }
            return anagrams;
        }

    }
};
