class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0;
        int prod=1;
        int n=nums.size();
        int cnt=0;
        while(j<n){
            prod=prod*nums[j];
              if(prod>=k && i<n){
                while(prod>=k && i<n){
                prod=prod/nums[i];
                 i++;   
                }
            }
            if(prod<k) {
                cnt+=j-i+1;
                
            }
          
            j++;
        }
        return cnt;
    }
    
};