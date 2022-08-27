class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len=1,mx=1;
       // for(int n:nums) cout<<n<<" ";
        if(nums.size()==0)return 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-1==nums[i-1]){
                len++;
            }
            else if(nums[i]!=nums[i-1]){
                mx=max(len,mx);
                len=1;
            }
            mx=max(len,mx);
        }
        return mx;
    }
};