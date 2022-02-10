class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int closest=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            if(i>0 and nums[i]==nums[i-1])continue;
            int lo=i+1, hi=n-1;
            while(lo<hi){
                int currsum=nums[i]+nums[lo]+nums[hi];
                if(currsum == target)return currsum;
                else if(abs(target-currsum)<abs(target-closest)){
                    closest=currsum;
                }
                else if(currsum<target){
                    lo++;
                }
                else hi--;
            }
        }
        return closest;
    }
};