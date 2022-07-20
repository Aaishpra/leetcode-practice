class Solution {
public:
    bool isValid(vector<int> &nums,int mid,int th){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]%mid==0?nums[i]/mid:nums[i]/mid+1);           
            if(sum>th){
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int th) {
        int lo=1;
        int hi=*max_element(nums.begin(),nums.end());
        int res=hi;
     
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isValid(nums,mid,th)){
                res=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return res;
    }
};