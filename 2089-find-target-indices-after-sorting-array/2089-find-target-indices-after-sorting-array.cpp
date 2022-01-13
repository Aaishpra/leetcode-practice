class Solution {
public:
    int first(vector<int>& nums,int target){
        int lo=0;
        int hi=nums.size()-1;
        int res=nums.size();
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
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
         int fi=first(nums,target);
        int la=last(nums,target);
        
        vector<int> ans;
       for(int i=fi;i<=la;i++) ans.push_back(i);
        return ans;
        
    }
};