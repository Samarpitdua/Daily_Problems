class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
            int ct = 0;
             sort(people.begin() , people.end());
            int n = people.size();
            for(int i = 0 , j = n - 1 ; i <= j ; )
            {
                if(people[i] + people[j] <= limit )
                {
                    ct++;
                    i++;
                    j--;
                }
                else
                {
                    ct++;
                    j--;
                }
            }
            return ct;
    }
};