class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
     int n=nums.size();
        int down=1,up=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                up=down+1;
                //down=down;
            }
            else if(nums[i]<nums[i-1]){
                down=up+1;
                //up=up;
            }
         
        }
        return max(up,down);
    }
};