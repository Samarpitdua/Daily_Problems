class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0; 
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i+1; j < points.size(); ++j) {
                for (int k = j+1; k < points.size(); ++k ){
                    double a = sqrt(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2)), 
                    b = sqrt(pow(points[j][0] - points[k][0], 2) + pow(points[j][1] - points[k][1], 2)), 
                    c = sqrt(pow(points[k][0] - points[i][0], 2) + pow(points[k][1] - points[i][1], 2)), 
                    s = (a + b + c)/2; 
                    ans = max(ans, sqrt(s*(s-a)*(s-b)*(s-c)));
                }
            }
        }
        return ans; 
    }
};