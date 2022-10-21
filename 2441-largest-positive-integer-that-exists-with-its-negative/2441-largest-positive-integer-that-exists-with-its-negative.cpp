class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mx=-1;
        
        for(int n:nums){
            mp[n]++;
        }
        
        for(auto m:mp){
            int res=-(m.first);
            if(mp.count(res)!=0 and m.first>mx){
                mx=m.first;
            }
        }
        return mx;
    }
};