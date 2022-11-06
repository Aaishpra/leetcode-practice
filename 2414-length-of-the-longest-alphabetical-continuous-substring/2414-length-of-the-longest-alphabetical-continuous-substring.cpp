class Solution {
public:
    int longestContinuousSubstring(string nums) {
        int cnt=1,mx=1;
        
        for(int i=0;i<nums.length()-1;i++){
            if(nums[i]-'0'==nums[i+1]-'0'-1) cnt++;
            else cnt=1;
            mx=max(cnt,mx);
        }
        return mx;
    }
};