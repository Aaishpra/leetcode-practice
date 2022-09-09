class Solution {
public:
     static bool mysort(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];

    }
    int numberOfWeakCharacters(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),mysort);
        int cnt=0;
        int n=nums.size();
        int mx=nums[n-1][1];
        for(int i=n-1;i>=0;i--){
            if(nums[i][1]<mx){
                cnt++;
            }
            mx=max(mx,nums[i][1]);
        }
        return cnt;
    }
};