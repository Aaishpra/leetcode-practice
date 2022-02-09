class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        vector<int> odd,even;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2)odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
      //  vector<int> ans(nums.size());
        
        for(int i = 0; i<nums.size(); i+=2) {
		nums[i] = even[i/2];
	}
	//filling odd spaces
	for(int i = 1; i<nums.size(); i+=2) {
		nums[i] = odd[i/2];
	}
	return nums;
        //return ans;
    }
};