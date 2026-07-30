//this one is still a little confusing for me, but basically we can add the indices
//into the stack one by one. at each iteration, we are checking if the temperature
//we are currently at is greater than the most recently entered temperature in the stack
//if so we will stay in the while loop until the stack is empty or the temperature is not
//larger than the one at the top of the stack.
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> tempStack;
        vector<int> result(temperatures.size());

        for(size_t i = 0; i < temperatures.size(); i++) {
            
            while(tempStack.size() > 0 && temperatures[i] > temperatures[tempStack.back()]) {

                result[tempStack.back()] = i - tempStack.back();
                tempStack.pop_back();

            }
            tempStack.push_back(i);
            //result[tempStack.back()] = days;

        }
        return result;
    }
};
