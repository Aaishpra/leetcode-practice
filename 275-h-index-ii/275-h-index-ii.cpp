class Solution {
public:
    int hIndex(vector<int>& citations) {
        int lo=0;
        int len=citations.size();
        int hi=citations.size()-1;
       // if(citations.size()==1)return citations[0];
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(len-mid==citations[mid]){
                return citations[mid];
            }
            else if(len-mid<citations[mid]){
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return len-(hi+1);
    }
};