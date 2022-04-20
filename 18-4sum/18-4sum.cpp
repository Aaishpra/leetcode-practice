class Solution {
    public:
     vector<vector<int>> res;
      void threeSum(vector<int>& nums,int t,int start,int offset) {
       
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=start;i<n-2;i++){
            //Duplicates na aajye same number m
             if(i>start && (nums[i]==nums[i-1]) )continue;
            int target=t-nums[i];
            int lo=i+1, hi=n-1;
            while(lo<hi){
                if(nums[lo]+nums[hi]<target) lo++;
                else if(nums[lo]+nums[hi]>target)hi--;
                else {
                    res.push_back({nums[i],nums[lo],nums[hi],offset});
                    //Lo ar hi k duplicates htane k liye
                    while(lo+1<hi and nums[lo]==nums[lo+1])lo++;
                    while(lo+1<hi and nums[hi]==nums[hi-1])hi--;
                    lo++,hi--;
                }
            }
        }
       
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)return {};
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 and nums[i]==nums[i-1])continue;
            threeSum(nums,target-nums[i],i+1,nums[i]);
        }
        return res;
    }
};