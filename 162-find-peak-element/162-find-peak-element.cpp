class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1;
   
        if(n==1)return 0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mid>0 and mid<n-1){
                if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]){
                    return mid;
                }
                else if(nums[mid-1]>nums[mid]){
                    hi=mid-1;
                }
                else if(nums[mid+1]>nums[mid]){
                    lo=mid+1;
                }
            }
            if(mid==0){
                if(nums[0]>nums[1]) return 0;
                else return 1;
            }
            if(mid==n-1){
                if(nums[n-1]>nums[n-2])return n-1;
                else return n-2;
            }
        }
        return 0;
    }
};