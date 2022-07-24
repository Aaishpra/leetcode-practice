class Solution {
public:
long long countSetBits(unsigned int n)
{
    long long count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
    long long countExcellentPairs(vector<int>& arr, int target) {
         unordered_set<int> m(arr.begin(),arr.end());
        vector<int> res;
        for(auto& i:m){
            res.push_back(countSetBits(i));
        }
        sort(res.begin(),res.end());
        long long ans=0;
        
        for(int i=0;i<res.size();i++){
            auto it=lower_bound(res.begin(),res.end(),target-res[i]);
            ans+=res.end()-it;
        }
        return ans;
    }
};