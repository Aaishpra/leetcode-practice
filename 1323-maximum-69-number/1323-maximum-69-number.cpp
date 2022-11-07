class Solution {
public:
    int maximum69Number (int num) {
        vector<int> nums;
        
        while(num>0){
            nums.push_back(num%10);
            num=num/10;
        }
        reverse(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=9) {
                nums[i]=9;
                break;
            }
        }
        int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        ans += nums[i]*pow(10, n-i-1);
    }
    return ans;
    }
};