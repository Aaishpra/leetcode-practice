class Solution {
public:
    int countElements(vector<int>& nums) {
        int maxe=INT_MIN;
        int mine=INT_MAX;
        
        for(int num:nums){
            maxe=max(maxe,num);
            mine=min(mine,num);
        }
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] < maxe and nums[i]>mine) count++;
        }
        return count;
    }
};