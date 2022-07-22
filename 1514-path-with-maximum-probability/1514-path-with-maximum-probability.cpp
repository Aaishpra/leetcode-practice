class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
          
        vector<vector<pair<int, double>>> ar(n);
        vector<double> prob(n, 0);
        priority_queue<pair<double, int>> pq;
        
        for(int i = 0; i < edges.size(); i++) {
            ar[edges[i][0]].push_back({edges[i][1], succProb[i]});
            ar[edges[i][1]].push_back({edges[i][0], succProb[i]});   
        }
    
        pq.push({1.0, start});
        
           // can't intiaize it with 0 as it we are using multiplication
        prob[start] = 1;  
        
        while(!pq.empty()){
            int node = pq.top().second;
            double prevProbability = pq.top().first;
            pq.pop();
            
            for(auto child : ar[node]){
                if(prevProbability * child.second > prob[child.first]){
                    prob[child.first] = prevProbability * child.second;
                    pq.push(make_pair(prob[child.first], child.first));
                }
            }
        }
        
        return prob[end];
    }
};