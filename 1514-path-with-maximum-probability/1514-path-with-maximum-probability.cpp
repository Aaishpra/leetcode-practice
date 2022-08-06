class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& succProb, int start, int end) {
        vector<double> prob(n,0);
        priority_queue<pair<double,int>> pq;
        vector<vector<pair<int,double>>> ar(n);
        for(int i=0;i<e.size();i++){
            ar[e[i][0]].push_back({e[i][1],succProb[i]});
            ar[e[i][1]].push_back({e[i][0],succProb[i]});
        }
        prob[start]=1;//cant take 0 because of multiplication
        pq.push({1.0,start});
        
        while(!pq.empty()){
            int cur=pq.top().second;
            double cur_prob=pq.top().first;
            pq.pop();
            for(auto child:ar[cur]){
                if(cur_prob*child.second>prob[child.first]){
                    prob[child.first]=cur_prob*child.second;
                    pq.push({prob[child.first],child.first});
                }
            }
        }
        return prob[end];
    }
};