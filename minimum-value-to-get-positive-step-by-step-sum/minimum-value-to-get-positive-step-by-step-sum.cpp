class Solution {
public:
    int minStartValue(vector<int>& nums) {
     int sum=0; int ans=0;
        for(int ar: nums){
            sum+=ar;
            ans=min(ans,sum);
        }
        return -ans+1;
    }
};