class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashset(nums1.begin(),nums1.end());
        vector<int> res;
        for(int i:nums2){
            if(hashset.erase(i)) res.push_back(i);
        }
        return res;
    }
};