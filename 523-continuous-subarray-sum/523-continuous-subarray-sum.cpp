class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
        mp[0]=-1;
        int j=0;
        long long sum=0;
        long long rem;
        while(j<nums.size()){
            sum+=nums[j];
            rem=sum%k;
            if(mp.find(rem)==mp.end()){
                mp[rem]=j;
            }
            else if(mp.find(rem)!=mp.end() and j-(mp[rem]+1)+1>=2)
                return true;
            j++;
        }
        return false;
    }
};