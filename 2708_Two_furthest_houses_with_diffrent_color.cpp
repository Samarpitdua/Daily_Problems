class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = -1;
        int first_house , second_house;
        for(int i = 0;i < colors.size();i++)
        {
            for(int j = i;j < colors.size();j++)
            {
                first_house = i;
                second_house = j;
                if(colors[first_house] != colors[second_house])
                {
                    ans=max(ans,second_house - first_house);
                }
            }
        }
        return ans;
        
    }
};
