class Solution {
public:
    bool IsValid(vector<int>& nums,int m,int mx){
        int count=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mx){
                count++;
                sum=nums[i];
            }
        }
        return count>m?false:true;
    }
    int splitArray(vector<int>& nums, int m) {
        int mx=INT_MIN,sum=0;
        for(int i=0;i<nums.size();i++){
sum+=nums[i];
        mx=max(mx,nums[i]);
        }
        int res=0;
        int lo=mx,hi=sum;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(IsValid(nums,m,mid)==true){
                res=mid;hi=mid-1;
            }
            else lo=mid+1;
        }
        return res;
    }
};