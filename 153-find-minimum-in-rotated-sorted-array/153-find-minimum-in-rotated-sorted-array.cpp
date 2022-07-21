class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1;
        if(n==1)return nums[0];
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;
            if(nums[mid]<nums[next] and nums[mid]<nums[prev])return nums[mid];
            if(nums[mid]>nums[hi]){
            lo=mid+1;
            }
            else hi=mid-1;
        }
        return -1;
    }
};