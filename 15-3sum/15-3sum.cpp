class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     if(nums.size()<3)return {};
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 and nums[i]==nums[i-1])continue;
            int target=0-nums[i];
            int lo=i+1,hi=n-1;
            while(lo<hi){
                if(nums[lo]+nums[hi]<target)lo++;
                else if(nums[lo]+nums[hi]>target)hi--;
                else {
                    res.push_back({nums[lo],nums[hi],nums[i]});
                    while(lo+1<hi and nums[lo]==nums[lo+1])lo++;
                    while(lo+1<hi and nums[hi]==nums[hi-1])hi--;
                    lo++;
                    hi--;
                }
            }
        }
        return res;
    }
};