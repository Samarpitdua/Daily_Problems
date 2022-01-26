vector<int>seg(500000 , 0);
int n;
class NumArray {
public:
    
    void build(int low, int high, vector<int>& arr, int ind, vector<int>& seg)
{
    if(low == high)
    {
        seg[ind] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(low, mid, arr, 2 * ind + 1, seg);
    build(mid + 1, high, arr, 2 * ind + 2, seg);
    seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
}
    int query(int ind, int low,int high,int l,int r,vector<int>& seg)
    {
        if(low >= l and high <= r)
            return seg[ind];
        if(low > r or high < l)
            return 0;
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r, seg);
        int right = query(2 * ind + 2, mid + 1, high, l, r, seg);
        return (left + right);
    }  
    void update2(int ind, int low, int high, vector<int>& seg,int indToUpdate,int upd)
    {
        if(low==high)
        {
            seg[ind] = upd;
            return;
        }
        int mid = (low + high)/ 2;
        if (indToUpdate <= mid)
            update2(2 * ind + 1, low, mid, seg, indToUpdate, upd);
        else
            update2(2 * ind + 2, mid + 1, high, seg, indToUpdate, upd);
        seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
    }
    NumArray(vector<int>& nums) {
        
        n = nums.size();
        seg.resize(4 * n);
        build(0 , nums.size() - 1 , nums , 0 , seg);
    }


    void update(int index, int val) {
        //cout<<n<<" ";
              update2(0 , 0 , n - 1 , seg , index , val);
    }
    
    int sumRange(int left, int right) {
       return  query(0 , 0 , n - 1 , left , right ,seg);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */