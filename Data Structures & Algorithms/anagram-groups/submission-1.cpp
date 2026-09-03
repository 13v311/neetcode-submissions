class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //redoing this problem with a clean slate, this is retry #1
        //im noticing my intuition when it comes to character counts is immediately to do an unordered map for hashing, but thats not always gonna be the right choice and i have to realize that; while i still use hashing here, its not necessarily in the way i thought
        //in this solution, map may not be O(n*m) because of its ordering when trying to find a value, but unordered_map would be. im not sure how to make a custom hash for unordered_map so we are just keeping it as map. alternatively, we could use a string as representation instead of a vector<int>, which i think a string is what we used the first time.
        vector<vector<string>> anagrams;
        map<vector<int>, vector<string>> charCounts;
        for(size_t i = 0; i < strs.size(); i++) {
            vector<int> count(26, 0);
            for(size_t j = 0; j < strs[i].length(); j++) {
                count[strs[i][j] - 'a'] += 1;
            }

          
            charCounts[count].push_back(strs[i]);

        }
        for(auto vecPair : charCounts) {
            anagrams.push_back(vecPair.second);
        }
        return anagrams;
    }
        
        
};
