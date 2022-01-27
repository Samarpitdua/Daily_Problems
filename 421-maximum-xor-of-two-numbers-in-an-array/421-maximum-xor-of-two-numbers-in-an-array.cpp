class Trie
{
    public:
	struct Node
    {
      	Node *links[2];
    };
    Node* root;
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *temp = root;
        for(int i = 31 ; i >= 0 ;i--)
        {
            int bit = (1 & num >> i);
            if(!temp -> links[bit])
            {
                Node* newnode = new Node();
                temp -> links[bit] = newnode;
            }
            temp = temp -> links[bit];       
        }
    }
    int findMax(int num)
    {
        Node *temp = root;
        int maxNum = 0;
        for(int i = 31 ; i >= 0 ;i--)
        {
            int bit = (1 & num >> i);
            if(temp -> links[!bit])
            {
                maxNum = maxNum | (1 << i);
                temp = temp -> links[!bit];
            }
            else
                temp = temp -> links[bit];       
        }
        return maxNum;
    }
};
class Solution {
public:
    Trie obj;
    int findMaximumXOR(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++)
            obj.insert(nums[i]);
        int maxi = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int ct = obj.findMax(nums[i]);
            maxi = max(maxi , ct);
        }
        return maxi;
    }
};