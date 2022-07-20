class Solution {
public:
    bool isValid(vector<int>& c,int candy,long long k){
        long long count = 0;
        for(int i=0;i<c.size();i++)
        {
            count+= c[i]/candy; // counting number of children that can have piles with 'candy' number of candies
        }
        
        if(count>=k)
            return true;
        else
            return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int lo=1;
        int hi=*max_element(candies.begin(),candies.end());
        int res=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isValid(candies,mid,k)){
                res=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return res;
    }
};