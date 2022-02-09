#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n , k;
        cin>>n>>k;
        vector<int>a(n) , b(n);
        for(int i = 0 ; i < n ;i++)
            cin>>a[i];
        int j = 0;
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i = 0; i < n ;i++)
        {
            if(pq.size() < k)
                {
                    pq.push(a[i]);
                }
            else
            {
                pq.push(a[i]);
                b[j++] = pq.top();
                pq.pop();
            }
        }
        while(!pq.empty())
        {
            b[j++] = pq.top();
            pq.pop();
        }
        for(auto x : b)
            cout<<x<<" ";
        cout<<"\n";
    }
	//code
	return 0;
}