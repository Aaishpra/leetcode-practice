class Solution {
public:
    static bool mysort(vector<int> a,vector<int> a1){
        return a[1]>a1[1];
    }
    int maximumUnits(vector<vector<int>>& b, int t) {
     sort(b.begin(),b.end(),mysort);  
        int ans=0;
        for(int i=0;i<b.size();i++){
            int x=min(b[i][0],t);
            ans+=x*b[i][1];
            t-=x;
            if(!t)break;
        }
        return ans;
    }
};