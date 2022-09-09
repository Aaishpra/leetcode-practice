class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int mx=0;
        int i=0,j=0;
        int cnt=0;
        while(j<nums.size()){
            if(nums[j]==0) cnt++;
            if(cnt<=k){
                mx=max(j-i+1,mx);

            }
            else if(cnt>k){
                while(cnt>k){
                    if(nums[i]==0)
                        cnt--;
                        i++;
                }
            }
            j++;
        }
        return mx;
    }
};