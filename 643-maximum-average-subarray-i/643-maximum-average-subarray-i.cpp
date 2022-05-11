class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    
        double sum=0;
        double res=INT_MIN;
        int i=0,j=0;
        int n=nums.size();
        if(n==1) return nums[0]/k;
        while(j<n){
            sum+=nums[j];
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                res=max(res,sum);
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return res/k;
    }
};