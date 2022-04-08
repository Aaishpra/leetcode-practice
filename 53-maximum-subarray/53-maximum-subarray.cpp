class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int cur=0;
        int best=INT_MIN;
        for(int num:nums){
            cur=max(cur+num,num);
            best=max(cur,best);
        }
        return best;
    }
};