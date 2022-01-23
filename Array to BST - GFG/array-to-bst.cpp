// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
struct Node
{
    Node* left;
    Node* right;
    int val;
    Node(int key)
    {
        val = key;
        left = NULL , right = NULL;
    }
};

    Node* makeBST(int l , int r , vector<int>& nums)
    {
        if(l > r)
        {
            return NULL;
        }
        int mid = (l+r)/2;
    
      Node* root = new Node(nums[mid]);
            root -> left = makeBST(l , mid - 1 , nums);
            root -> right = makeBST(mid + 1 , r ,nums);
            return root;
        
    }
    void preorder(Node* root , vector<int>& ans)
    {
        if(!root)
            return;
        ans.push_back(root -> val);
        preorder(root -> left , ans);
        preorder(root -> right , ans);
    }
    vector<int> sortedArrayToBST(vector<int>& nums)
    {
        vector<int> ans;
        int n = nums.size();
        Node* root = makeBST(0 , n - 1 , nums);
        preorder(root , ans);
        return ans;// Code here
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends