class Solution {
public:
    bool isValid(vector<int> &nums,int n, int mid){
        int curh=0;
        for(int i:nums){
            curh+=i/mid;
            if(i%mid!=0)curh++;
        }
        return curh<=n;
    }
    int minimizedMaximum(int n, vector<int>& nums) {
        int lo=1, hi=*max_element(nums.begin(),nums.end());
        int ans = 0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isValid(nums,n,mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};