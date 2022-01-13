class Solution {
public:
    int first(vector<int>& nums,int target){
        int lo=0;
        int hi=nums.size()-1;
        int res=-1;
        while(lo<=hi){
            int mid= lo+ (hi-lo)/2;
            if(nums[mid]==target){
                res=mid;
                hi=mid-1;
            }
            else if(nums[mid]<target){
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return res;
    }
    int last(vector<int>& nums,int target){
        int lo=0;
        int hi=nums.size()-1;
        int res=-1;
        while(lo<=hi){
            int mid= lo+ (hi-lo)/2;
            if(nums[mid]==target){
                res=mid;
                lo=mid+1;
            }
            else if(nums[mid]<target){
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int fi=first(nums,target);
        int la=last(nums,target);
        
        vector<int> ans;
        ans.push_back(fi);
        ans.push_back(la);
        return ans;
    }
};