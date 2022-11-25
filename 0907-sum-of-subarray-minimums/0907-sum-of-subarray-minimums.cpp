class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
         long result = 0, i = 0, n = arr.size();
        vector<int> s1(1, -1), s2(1, n), tmp(n, 0);
        for (; i < n; s1.push_back(i++)) {
            while (s1.back() >= 0 && arr[s1.back()] >= arr[i]) s1.pop_back();
            tmp[i] = arr[i] * (i - s1.back());
        }
        for (i--; i >= 0; s2.push_back(i--)) {
            while (s2.back() < n && arr[s2.back()] > arr[i]) s2.pop_back();
            result = (result + tmp[i] * (s2.back() - i)) % 1000000007;
        }
        return result;
    }
};