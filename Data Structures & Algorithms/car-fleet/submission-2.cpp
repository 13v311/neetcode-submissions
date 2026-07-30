//we can first sort the array to go in increasing order of the positions for each car
//any car behind another has a chance to merge if it catches up. they have to be in pairs
//of position and speed so that the sorting does not mismatch the order between
//positon and speed. then once sorted we can start with the highest value and
//work our way down. each car has an amt of time it takes to get to target
//calculated by (target - pos) / speed. we add a time into the stack each time
//it is greater than what we currently have in our stack. essentially, that means
//that the time it takes for that car to get there will never merge with any other
//fleet in the stack. if it is less than the stack tho, then it will merge, so we 
//do not add it into the stack.
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<double> fleetTimes;
        vector<pair<double, double>> cars;
        for(size_t i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());

        for(int i = cars.size() - 1; i >= 0; i--) {
            double time = (target - cars[i].first) / cars[i].second;
            if(fleetTimes.size() < 1 || fleetTimes.back() < time) {
                fleetTimes.push_back(time);
            }
        }
        return fleetTimes.size();
    }
};
