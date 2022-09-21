class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int len = nums.size(), i= 0;
		while ( i < len )
		{
			 if ( nums[i] == val )
			 {
				 nums[i] = nums[len - 1];
				 -- len;
			 }
				
			else ++i;
		}
		 return len;  
    }
};