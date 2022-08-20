class Solution {
public:
    bool hasAlternatingBits(int n) {
    
        vector<int> nums;
        while(n>0){
            nums.push_back(n%2);
            n=n>>1;
        }
        
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]^nums[i]==0)
                return false;
        }
        return true;
    }
};