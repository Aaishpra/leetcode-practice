class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res=0,cnt=0;
        int i=0,j=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]==0) cnt++;
            if(cnt<=k){
                res=max(res,j-i+1);
                j++;
            }
            else if(cnt>k){
                while(cnt>k){
                    if(nums[i]==0) cnt--;
                    i++;
                }
                j++;
            }
        }
        return res;
    }
};