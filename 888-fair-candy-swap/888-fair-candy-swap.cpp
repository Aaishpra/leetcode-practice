class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
       
        sort(aliceSizes.begin(),aliceSizes.end());
        sort(bobSizes.begin(),bobSizes.end());
        
        int sum1=0,sum2=0;
        vector<int>ans;
        
        for(int i:aliceSizes)
            sum1+=i;
        for(int i:bobSizes)
            sum2+=i;
        
        int diff=(sum2-sum1)/2;
        
        for(int i:aliceSizes)
        {
            int lc=0,uc=bobSizes.size()-1,mid=0;
            while(lc<=uc)
            {
                mid=lc+(uc-lc)/2;
                if(i+diff==bobSizes[mid])
                {
                    ans.push_back(i);
                    ans.push_back(i+diff);
                    return ans;
                }
                else if(i+diff<bobSizes[mid])
                    uc=mid-1;
                else
                    lc=mid+1;
            }
        }
        return ans;   
    }
};