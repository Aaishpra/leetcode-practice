class Solution {
public:
      bool isValid(vector<int> &nums,int m,long mx){
        int count=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mx){
            count++;
            sum=nums[i];}
        }
        return count<m;
    }
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int mx=INT_MIN,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mx=max(mx,nums[i]);
        }
        int lo=mx, hi=sum;
        int res=-1;
        while(lo<=hi){
        long mid=lo+(hi-lo)/2;
            if(isValid(nums,m,mid)){
                res=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return res;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int ans=INT_MAX;
       sort(cookies.begin(),cookies.end());
        do{
            ans=min(ans,splitArray(cookies,k));
        }while(next_permutation(cookies.begin(),cookies.end()));
        return ans;
    }
};