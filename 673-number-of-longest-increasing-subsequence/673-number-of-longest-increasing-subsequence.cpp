class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> len(nums.size(),1);
        vector<int> cnt(nums.size(),1);
        int mx=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(len[j]+1>len[i]){
                        len[i]=len[j]+1;
                        cnt[i]=cnt[j];
                    }
                    else if(len[j]+1==len[i]){
                      //  len[i]=len[j];
                        cnt[i]+=cnt[j];
                    }
                }
            }
            mx=max(len[i],mx);
        }
      int res=0;
        
        // for(int n:cnt) cout<<n<<" ";
        // cout<<endl;
        for(int i=0;i<nums.size();i++){
            if(len[i]==mx){
                res+=cnt[i];
            }
        }
        return res;
    }
};