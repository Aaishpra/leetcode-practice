class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            //Duplicates na aajye same number m
             if(i>0 && (nums[i]==nums[i-1]) )continue;
            int target=0-nums[i];
            int lo=i+1, hi=n-1;
            while(lo<hi){
                if(nums[lo]+nums[hi]<target) lo++;
                else if(nums[lo]+nums[hi]>target)hi--;
                else {
                    res.push_back({nums[i],nums[lo],nums[hi]});
                    //Lo ar hi k duplicates htane k liye
                    while(lo+1<hi and nums[lo]==nums[lo+1])lo++;
                    while(lo<hi-1 and nums[hi]==nums[hi-1])hi--;
                    lo++,hi--;
                }
            }
        }
        return res;
    }
};