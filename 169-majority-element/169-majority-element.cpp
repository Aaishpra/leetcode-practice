class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x=0;
        int count=0;
        for(int num:nums){
            if(count==0) x=num,count=1;
            else if(x==num) count++;
            else count--;
        }
        count=0;
        for(int num:nums){
            if(num==x){
                count++;
            }
        }
        return count>(nums.size())/2?x:-1;
    }
};