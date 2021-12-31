class Solution {
public:
    int MAH(vector<int>& heights, int n) {
        //int n = heights.size();
        stack<pair<int,int>>st;
        vector<int> v(n) , v2(n) ;
        for(int i = n - 1; i >= 0; i--)
        {
            if(st.empty())
            {
                v[i] = n;
               // cout<<v[i]<<endl;
                st.push( { heights[i] , i } );
            }
            else
            {
                while(!st.empty() and st.top().first >= heights[i])
                    st.pop();
                if(st.empty())
                {
                    v[i] = n;
                    st.push( { heights[i] , i } );
                }
                else
                {
                    v[i] = st.top().second;
                    st.push( { heights[i] , i } );
                }
            }
            
        }
       // for(auto x : v )cout<< x << " ";
      //  reverse(v.begin() , v.end());
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++)
        {
            if(st.empty())
            {
                v2[i] = -1;
                st.push( { heights[i] , i } );
            }
            else
            {
                while(!st.empty() and st.top().first >= heights[i])
                    st.pop();
                if(st.empty())
                {
                    v2[i] = -1;
                    st.push( { heights[i] , i } );
                }
                else
                {
                    v2[i] = st.top().second;
                    st.push( { heights[i] , i } );
                }
            }
            
        }
        int maxi = 0;
        for(int i = 0; i < n ;i++)
        {
           // cout<<v[i]<<" "<<v2[i]<<" ";
            int temp = abs( ( v[i] - v2[i] ) - 1);
          //  cout<< temp << " ";
            temp *= heights[i];
            maxi = max(maxi , temp);
           // cout<<temp<<"\n";
        }
        return maxi;    
    }
    int maximalRectangle(vector<vector<char>>& matrix2) {
        int m = matrix2.size();
        int n = matrix2[0].size();
        int ans = 0;
        vector<vector<int>>matrix(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                matrix[i][j]=matrix2[i][j]-'0';
        }
        for(int i = 0; i < m ; i++)
        {
            vector<int>temp(n,0);
            for (int  j = 0; j < n ; j++)
            {
                
                if( matrix[i][j] == 0 )
                {
                    temp[j] = 0;
                }
                else
                {
                    if( i == 0 )
                        temp[j] = matrix[i][j];
                    else
                    temp[j] = matrix[i-1][j] + 1 ;
                    matrix[i][j] = temp[j] ;
                }
               // cout<<temp[j]<<" ";
            }
         //   for(auto x: temp)cout<<x<<" ";
            cout<<"\n";
            int maxi = MAH(temp , n);
            //cout<<maxi << " ";
            ans = max( maxi , ans );
        }
        return ans;
        
    }
};