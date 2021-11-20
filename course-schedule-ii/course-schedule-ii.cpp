class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
           vector<vector<int>> ar(numCourses);
        vector<int> in(numCourses,0);
        queue<int> q;
        for(auto p: prerequisites){
            ar[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(in[i]==0) q.push(i); // Adding elements in toposort acc to Kahns' algo   
        }
    
        vector<int> res;
        while(!q.empty()){
            int cur=q.front();
            
            res.push_back(cur);
            q.pop();
            for(auto child: ar[cur]){
                in[child]--;
                if(in[child]==0) q.push(child); // Adding elements in toposort acc to Kahns' algo   
            }
        }
        if(res.size()==numCourses){
        return res;
        }
        
        return {};
    }
};