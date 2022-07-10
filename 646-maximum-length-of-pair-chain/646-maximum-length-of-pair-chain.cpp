 bool cmp(vector<int> a, vector<int> b) {
    if(a[1] < b[1]) {
        return true;
    }
    return false;
}  
class Solution {
public:

int findLongestChain(vector<vector<int>>& pairs) {
    
        int n=pairs.size();
        sort(pairs.begin(), pairs.end(), cmp);
        int cur=pairs[0][1];
        int len=1;
        for(int i=1;i<n;i++){
            if(cur<pairs[i][0]){
                cur=pairs[i][1];
                len++;
            }
        }
        return len;
    }
};