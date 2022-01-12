class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();  
        for(int i = 0 ; i < n ; i++)
        {
            if(st.empty())
                st.push(asteroids[i]);
            else
            {
                if(asteroids[i] >= 0 and st.top() <= 0)
                {
                    st.push(asteroids[i]);
                //     if(asteroids[i] > abs(st.top()))
                //     {
                // while(!st.empty() and st.top() < 0 and asteroids[i] > abs(st.top()))
                // {
                //     st.pop();
                // }
                //         if(!st.empty())
                //         {
                //             if(st.top() > 0)
                //             {
                //                 st.push(asteroids[i]);
                //                 continue;
                //             }
                //             else if(abs(st.top()) == asteroids[i])
                //             {
                //                 st.pop();
                //                 continue;
                //             }
                //             else
                //             {
                //                 continue;
                //             }
                //         }
                //         else
                //             st.push(asteroids[i]);
                //     }
                //       else if(asteroids[i] == abs(st.top()))
                //        {
                //            st.pop();
                //        }
                //        else
                //        {
                //            continue;
                //        }
                       
                }
                else if(asteroids[i] < 0 and st.top() > 0)
                {
                    if(abs(asteroids[i]) > abs(st.top()))
                    {
            while(!st.empty() and st.top() > 0 and abs(asteroids[i]) > abs(st.top()))
                {
                    st.pop();
                }
                        if(!st.empty())
                        {
                            if(st.top() < 0)
                            {
                                st.push(asteroids[i]);
                                continue;
                            }
                            else if(abs(st.top()) == abs(asteroids[i]))
                            {
                                st.pop();
                                continue;
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else
                            st.push(asteroids[i]);
                    }
                      else if(abs(asteroids[i]) == st.top())
                       {
                           st.pop();
                       }
                       else
                       {
                           continue;
                       }
                }
                else
                    st.push(asteroids[i]);
                    
            }
        }
                       vector<int> ans;
                       while(!st.empty())
                       {
                           ans.push_back(st.top());
                           st.pop();
                       }
                       reverse(ans.begin() , ans.end());
                       return ans;
    }
};