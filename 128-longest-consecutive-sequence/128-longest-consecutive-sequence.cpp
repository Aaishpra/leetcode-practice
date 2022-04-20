class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     unordered_set<int> hashset;
        for(int num:nums){
            hashset.insert(num);
        }
        int mx=0;
        for(int num:nums){
            if(hashset.find(num-1)==hashset.end()){
                int curr=num;
                int currs=1;
                while(hashset.find(curr+1)!=hashset.end()){
                    curr+=1;
                    currs+=1;
                }
            
            mx=max(currs,mx);
        }
        }
        return mx;
    }
};