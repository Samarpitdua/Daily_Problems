class FoodRatings {
public:
    map<string , set<pair<int , string>>> mp;
    unordered_map<string , string> fo;
    unordered_map<string , int> rat;
    FoodRatings(vector<string>& foods, vector<string>& c, vector<int>& ratings) {
        for(int i = 0 ; i < foods.size() ;i++){
            
            mp[c[i]].insert({-ratings[i] , foods[i]});
            fo[foods[i]] = c[i];
            rat[foods[i]] = -ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = fo[food];
        int rating = rat[food];
        mp[cuisine].erase({rating , food});
        mp[cuisine].insert({-newRating , food});
        rat[food] = -newRating;
    }
    
    string highestRated(string cuisine) {
        auto p = *(mp[cuisine].begin());
        return p.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */