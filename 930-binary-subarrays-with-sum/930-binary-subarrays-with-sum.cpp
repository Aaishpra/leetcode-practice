class Solution {
public:
    int atmost(vector<int>& nums,int goal){
          int i=0,j=0;
        int n=nums.size();
        int sum=0;
        int count=0;
        if(goal<0)return 0;
        while(j<n){
            sum+=nums[j];
           // if(sum<goal) j++;
            // if(sum==goal){
            //     count+=j-i+1;
            // }
            if(sum>goal){
                while(sum>goal){
                    sum-=nums[i];
                    i++;
                }
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
     return atmost(nums,goal)-atmost(nums,goal-1);
    }
};