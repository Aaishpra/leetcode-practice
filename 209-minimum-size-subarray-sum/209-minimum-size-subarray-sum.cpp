class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int i=0,j=0;
        
        long long sum=0;
        int mn=INT_MAX;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum<target){
                j++;
            }
            else if(sum>=target){
                while(sum>=target){
                mn=min(j-i+1,mn);
                sum-=nums[i];
                i++;
                }
                
                j++;
            }
        }
        return mn==INT_MAX?0:mn;
    }
};