class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     int i=0,j=0;
        
        int cnt=0,maxlen=0;
        while(j<nums.size()){
            if(nums[j]==0)cnt++;
            if(cnt<=k){
                maxlen=max(maxlen,j-i+1);
                j++;
            }
            else if(cnt>k){
                while(cnt>k){
                    if(nums[i]==0) cnt--;
                    i++;
                }
                j++;}
                
        }
        return maxlen;
    }
};