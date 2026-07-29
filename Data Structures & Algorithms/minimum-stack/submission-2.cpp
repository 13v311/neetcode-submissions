/*
we can use two separate vectors, one to represent the values and one to represent
the minimum value at each point. this is so that when we pop a value off, we
still remember what the minimum was. usually a stack can be represented just
by a vector, but a minstack requires a bit more like shown here!
*/
class MinStack {
private:
    vector<int> minstack;
    vector<int> minimums;

public:
    MinStack() {
        minstack = {};
        minimums = {};
    }
    
    void push(int val) {
       int min;
       if(minstack.size() > 0) {
            min = std::min(minimums.back(), val);
       } else {
        min = val;
       }

       minstack.push_back(val);
       minimums.push_back(min); 

    }
    
    void pop() {
        minstack.pop_back();
        minimums.pop_back();
    }
    
    int top() {
        return minstack.back();
    }
    
    int getMin() {
        return minimums.back();
    }
};
