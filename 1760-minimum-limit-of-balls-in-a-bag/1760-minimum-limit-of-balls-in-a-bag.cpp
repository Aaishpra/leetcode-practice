class Solution {
public:
    bool isValid(vector<int>& nums,int k,int mid){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=nums[i]/mid;
            if(nums[i]%mid==0) cnt--;
        }
        return cnt<=k;
    }
    int minimumSize(vector<int>& nums, int k) {
        int lo=1,hi=*max_element(nums.begin(),nums.end());
        int res=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isValid(nums,k,mid)){
                res=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return res;
    }
};