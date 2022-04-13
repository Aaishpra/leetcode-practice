class Solution {
public:
    bool myfunction (int i, int j) {
  return (i==j);
}

    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        set<int> ans;
        for(int num:nums){
            mp[num]++;
            if(mp[num]>n/3) ans.insert(num);
        }
        std::vector<int> output(ans.begin(), ans.end()); 
        //std::unique (ans.begin(), ans.end(), myfunction); 
        return output;
    }
};