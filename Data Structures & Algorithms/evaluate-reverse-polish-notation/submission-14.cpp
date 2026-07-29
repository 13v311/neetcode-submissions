//we can easily use a stack here to see what the result is. we take two 
//numbers off the stack (the top 2) each time we run into an operator
//then we put the value from performing that operation back into the stack
//eventually we will be left with just 1 number in the stack!
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result;
        vector<int> nums;

        for(size_t i = 0; i < tokens.size(); i++) {
            if(tokens[i][0] == '-' && tokens[i].length() > 1) {
                int num = stoi(tokens[i].substr(1));
                nums.push_back(num * -1);

            } else if(isdigit(tokens[i][0])) {
                nums.push_back(stoi(tokens[i]));

            } else {
                int num1 = nums.back();
                nums.pop_back();
                int num2 = nums.back();
                nums.pop_back();

                if(tokens[i] == "+") {nums.push_back(num1 + num2);}
                else if(tokens[i] == "-") {nums.push_back(num2-num1);}
                else if(tokens[i] == "*") {nums.push_back(num1*num2);}
                else if(tokens[i] == "/") {nums.push_back(num2/num1);}


            }
            result = nums.back();
        }
        //int result = nums.back();
        nums.clear();
        return result;
    }
};
