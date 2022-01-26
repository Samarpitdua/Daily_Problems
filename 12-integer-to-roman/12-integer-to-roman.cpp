class Solution {
public:
    string intToRoman(int num) {
      int temp;
    string ans = "";
    vector<string> ans2;
        while(1){
            temp = num % 10;
            num /= 10;
            if(temp == 1)
                ans += 'I';
            else if(temp == 2)
                ans += "II";
            else if(temp == 3)
                ans += "III";
            else if(temp == 4)
                ans += "IV";
            else if(temp == 5)
                ans += "V";
            else if(temp == 6)
                ans += "VI";
            else if(temp == 7)
                ans += "VII";
            else if(temp == 8)
                ans += "VIII";
            else if(temp == 9)
                ans += "IX";
            
            ans2.push_back(ans);
            if(!num)
                break;
            ans = "";
            temp = num % 10;
            num /= 10;
            if(temp == 1)
                ans += 'X';
            else if(temp == 2)
                ans += "XX";
            else if(temp == 3)
                ans += "XXX";
            else if(temp == 4)
                ans += "XL";
            else if(temp == 5)
                ans += "L";
            else if(temp == 6)
                ans += "LX";
            else if(temp == 7)
                ans += "LXX";
            else if(temp == 8)
                ans += "LXXX";
            else if(temp == 9)
                ans += "XC";
            
            ans2.push_back(ans);
            ans = "";
            if(!num)
                break;
            temp = num % 10;
            num /= 10;
            if(temp == 1)
                ans += 'C';
            else if(temp == 2)
                ans += "CC";
            else if(temp == 3)
                ans += "CCC";
            else if(temp == 4)
                ans += "CD";
            else if(temp == 5)
                ans += 'D';
            else if(temp == 6)
                ans += "DC";
            else if(temp == 7)
                ans += "DCC";
            else if(temp == 8)
                ans += "DCCC";
            else if(temp == 9)
                ans += "CM";
            ans2.push_back(ans);
            ans = "";
            if(!num)
                break;
            temp = num % 10;
            num /= 10;
            if(temp == 1)
                ans += 'M';
            else if(temp == 2)
                ans += "MM";
            else if(temp == 3)
                ans += "MMM";
            ans2.push_back(ans);
            ans ="";
            break;
        }
        ans = "";
        reverse(ans2.begin() , ans2.end());
        for(auto x : ans2)
        {
            ans += x;
        }
        return ans;
    }
};