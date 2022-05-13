class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //    int i = 0, j, k = 1, res = 0;
        // for (j = 0; j < A.length; ++j) {
        //     if (A[j] == 0) {
        //         k--;
        //     }
        //     while (k < 0) {
        //         if (A[i] == 0) {
        //             k++;
        //         }
        //         i++;
        //     }
        //     res = Math.max(res, j - i);
        // }
        // return res;
     int i=0,j=0;
        int mx=0;
        int cnt=1;
        while(j<nums.size()){
            if(nums[j]==0) cnt--;
          
            if(cnt<0){
                while(cnt<0){
                    if(nums[i]==0)cnt++;
                    i++;
                }
            }
            

                    mx=max(mx,j-i);
            
            j++;
        }
    return mx;
    }
};