class Solution
{
    public:
        bool validUtf8(vector<int> &data)
        {
            int ans = 0;
            for (auto c: data)
            {
                if (ans == 0)
                {
                    if ((c >> 5) == 0b110)
                        ans = 1;
                    else if ((c >> 4) == 0b1110)
                        ans = 2;
                    else if ((c >> 3) == 0b11110)
                        ans = 3;
                    else if ((c >> 7)) return false;
                }
                else
                {
                    if ((c >> 6) != 0b10)
                        return false;
                    ans--;
                }
            }
            return ans == 0;
        }
};