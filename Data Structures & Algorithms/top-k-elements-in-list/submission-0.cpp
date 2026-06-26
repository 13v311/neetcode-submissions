class Solution {
public:



    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> output;
        std::map<int, int> myMap;
        vector<std::pair<int, int>> vec;

        //we will add each distinct value of nums & the # of times they appear
        for(size_t i = 0; i < nums.size(); i++) {
            myMap[nums[i]]++;
        }

        //then put it into our vector of pairs to be sorted by value
        for(const auto& pair: myMap) {
            vec.push_back(pair);
        }

        //create a lambda comparator for sort, sorted by pair value NOT key
        std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        //ensure the loop stops adding final values after reached k
        size_t stop = 0;
        for(const auto& pair : vec) {
            if(stop == k) {break;}
            stop++;
            output.push_back(pair.first);
        }   
        return output; //all done
    }
};
