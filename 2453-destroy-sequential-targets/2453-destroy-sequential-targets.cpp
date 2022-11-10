class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<float,int> mp;
        int mx=INT_MIN;
        for(int n:nums){
            float rem=n%space;
            mp[rem]++;
            if(mx<mp[rem])
                mx=mp[rem];
        }
        
        int ans=INT_MAX;
        for(int n:nums){
            if(mx==mp[n%space])
                ans=min(ans,n);
        }
        return ans;
    }
};