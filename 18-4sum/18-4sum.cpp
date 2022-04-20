class Solution {
public:
    vector<vector<int>> res;
    void threesum(vector<int>& nums, int target,int start,int offset){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=start;i<n-2;i++){
            if(i>start and nums[i]==nums[i-1]) continue;
            int t=target-nums[i];
            int lo=i+1, hi=n-1;
            while(lo<hi){
                if(nums[lo]+nums[hi]<t)lo++;
                else if(nums[lo]+nums[hi]>t) hi--;
                else {
                    res.push_back({nums[lo],nums[hi],nums[i],offset});
                    while(lo+1<hi and nums[lo]==nums[lo+1])lo++;
                    while(lo+1<hi and nums[hi]==nums[hi-1])hi--;
                    lo++;
                    hi--;
                }
            }
        }
     //   return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<4)return {};
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            if(i>0 and nums[i]==nums[i-1])continue;
            int t=target-nums[i];
           
                threesum(nums,t,i+1,nums[i]);
                
            
        }
        return res;
    }
};