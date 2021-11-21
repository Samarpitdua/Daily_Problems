class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int totalSteps = 0,new_capacity = 0,steps = 0;
        for( int i = 0;i < plants.size();){
            if((new_capacity + plants[i]) > capacity)
            {
                steps*=2;
                totalSteps += steps;
                new_capacity = 0;
                steps/=2;
            }
            else
            {
                new_capacity = new_capacity + plants[i];
                steps++;
                i++;
            }
        }
        return (totalSteps + steps);
    }
};
