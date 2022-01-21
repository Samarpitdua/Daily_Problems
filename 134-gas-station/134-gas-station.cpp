class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int temp = 0, sum = INT_MAX , start = 0;
        for(int i = 0; i < n; i++)
		{
            temp += (gas[i]-cost[i]);
            if(temp < sum)
            {
                sum = temp;
                start = i + 1;
            }
        }
        return (temp < 0) ?  -1 : (start % n);
    }
};