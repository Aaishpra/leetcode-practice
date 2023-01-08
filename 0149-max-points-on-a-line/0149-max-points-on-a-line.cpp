class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        
        if(p.size()<=2) return p.size();
        
        int mx=2;
        
        for(int i=0;i<p.size();i++){
            for(int j=i+1;j<p.size();j++){
                int total=2;
                for(int k=0;k<p.size();k++){
                    if(k!=i and k!=j){
                        if((p[j][1]-p[i][1])*(p[k][0]-p[i][0])==(p[k][1]-p[i][1])*(p[j][0]-p[i][0])) 
                            total++;
                    }
                }
                mx=max(total,mx);
            }
        }
        return mx;
    }
};