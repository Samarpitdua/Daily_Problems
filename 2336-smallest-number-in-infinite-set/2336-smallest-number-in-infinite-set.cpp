class SmallestInfiniteSet {
public:
    map<int , int> mp;
    int ct;
    SmallestInfiniteSet() {
        mp.clear();
        ct = 0;
    }
    
    int popSmallest() {
        if(!mp.size())
        {
            // cout<<"hi";
            mp[1] = 1;
            return 1;
        }
        else
        {
            int  ct = 1;
            for(auto x : mp){
                if(x.first == ct)
                {
                    // cout<<x.first<<" ";
                    ct++;
                    continue;
                }
                else
                {
                    // cout<<ct<<" ";
                    mp[ct] = 1;
                    return ct;
                }
            }
            // cout<<mp.size()<<endl;
            mp[ct]++;
            // cout<<ct<<" ";
            return ct;
        }
    }
    
    void addBack(int num) {
        if(mp.find(num) != mp.end()){
            mp.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */