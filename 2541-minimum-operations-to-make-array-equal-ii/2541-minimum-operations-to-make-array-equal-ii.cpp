class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        if(k==0){
            return nums1==nums2?0:-1;
        }
        vector<long long> dif(n);
        for(int i=0;i<n;i++){
            dif[i]=nums1[i]-nums2[i];
        }
        long long sum=0;
        for(auto n:dif) {sum+=n;}
        if(sum!=0)return -1;
        long long res=0;
        
        for(int i=0;i<n;i++){
            if(dif[i]%k!=0){
                return -1;
            }
            dif[i]=dif[i]/k;
            if(dif[i]>0) res+=dif[i];
        }
       
        return res;
    }
};