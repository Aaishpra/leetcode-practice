class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int seq=1, max_seq=1;
        
        if(nums.empty()) return 0;
        
        for(int i=1; i<n; i++){
            
            if(nums[i] == (nums[i-1] + 1)) seq++;
            
            else if(nums[i]==nums[i-1]) continue;
            
            else seq = 1;
            
            max_seq = max(max_seq, seq);
        }
        return max_seq;
    }
};