class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int curr=0;
        int best=INT_MIN;
        
        for(int num:nums){
            curr=max(curr+num,num);
            best=max(best,curr);
        }
        return best;
    }
};