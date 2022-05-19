class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int e) {
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i=0;i<c.size();i++){
            double delta=double(c[i][0]+1)/(c[i][1]+1)-(double)(c[i][0])/(c[i][1]);
            pq.push({delta,{c[i][0],c[i][1]}});
        }
       while(e--){
           int p=pq.top().second.first;
           int t=pq.top().second.second;
           p++;
           t++;
           double newdelta=(double)(p+1)/(t+1)-(double)(p)/(t);
           pq.pop();
           pq.push({newdelta,{p,t}});
       }
        
        double ratio=0;
        while(!pq.empty()){
            ratio+=(double)(pq.top().second.first)/(pq.top().second.second);
            pq.pop();
        }
        return ratio/c.size();
    }
};