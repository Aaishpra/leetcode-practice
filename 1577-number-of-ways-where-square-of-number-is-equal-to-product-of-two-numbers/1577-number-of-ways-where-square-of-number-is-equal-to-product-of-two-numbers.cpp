#define ll long long int
class Solution {
public:
    
    int solve(vector<int> &nums1,vector<int> &nums2)
    {   unordered_map<ll,ll>mp;
        for(int i=0;i<nums2.size();i++)
        {
            for(int j=i+1;j<nums2.size();j++)
            {
                ll p=(long long)nums2[i]*nums2[j];
                mp[p]++;
            }
        }
        
        ll count=0;
       
        for(int i=0;i<nums1.size();i++)
        {
            ll p=(long long)nums1[i]*nums1[i];
            if(mp.find(p)!=mp.end())
            {
                count+=mp[p];
            }
        }
        return count;
    }
    
    int numTriplets(vector<int>& nums1, vector<int>& nums2) 
    {
        return solve(nums1,nums2)+solve(nums2,nums1);
    }
};