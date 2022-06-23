class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin() , courses.end() , [](vector<int>& a , vector<int>& b){
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int sum = 0;
        for(auto x : courses)
        {
            pq.push(x[0]);
            sum += x[0];
            if(sum > x[1])
            {
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};