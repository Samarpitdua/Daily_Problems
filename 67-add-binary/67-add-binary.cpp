class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        stack<char>st;
        for(;i>=0 or j>=0;)
        {
            if(i<0 and j>=0)
            {
                //cout<<"hi ";
                if(carry==1)
                {
                    if(b[j]=='1')
                    st.push('0');
                    else
                    {
                        st.push('1');
                        carry=0;
                    }
                }
                else
                {
                    if(b[j]=='0')
                    st.push('0');
                    else
                    {
                        st.push('1');
                    }
                }
                j--;
            }
            else if(j<0)
            {
                //cout<<"ika ";
                if(carry==1)
                {
                    if(a[i]=='1')
                    st.push('0');
                    else
                    {
                        st.push('1');
                        carry=0;
                    }
                }
                else
                {
                    if(a[i]=='0')
                    st.push('0');
                    else
                    {
                        st.push('1');
                    }
                }
                i--;
            }
            else
            {
                if(carry==0)
                {
                if(a[i]=='1' and b[j]=='1')
                    st.push('0'),carry=1;
                else if(a[i]=='0' and b[j]=='0')
                    st.push('0');
                else
                    st.push('1');
                }
                else
                {
                    if(a[i]=='1' and b[j]=='1')
                    st.push('1');
                    else if(a[i]=='0' and b[j]=='0')
                    st.push('1'),carry=0;
                    else
                    st.push('0');
                }
                i--,j--;
            }
        }
        if(carry)
            st.push('1');
        string s="";
        while(!st.empty())
        {
            s+=st.top();
            st.pop();
        }
        return s;
    }
};