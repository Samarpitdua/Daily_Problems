class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int a[26]={0};
        for(int i=0;i<text.size();i++)
            a[text[i]-'a']++;
        return min({a[1],a[0],a[11]/2,a[13],a[14]/2});
    }
};
