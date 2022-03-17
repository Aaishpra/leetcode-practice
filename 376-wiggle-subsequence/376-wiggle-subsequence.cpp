class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int f=1,d=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])f=d+1;
            else if(nums[i]< nums[i-1]) d=f+1;
        }
        return max(f,d);
    }
};