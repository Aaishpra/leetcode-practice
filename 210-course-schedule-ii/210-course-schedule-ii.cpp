class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
     vector<vector<int>> ar(n);
        vector<int> res;
        vector<int> in(n,0);
        
        queue<int> q;
        
        for(auto p:pre){
            ar[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int cur=q.front();
            res.push_back(cur);
            q.pop();
            for(int child:ar[cur]){
                in[child]--;
                if(in[child]==0) q.push(child);
            }
        }
        if(res.size()==n) return res;
        return {};
    }
};