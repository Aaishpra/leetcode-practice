class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            int pass=classes[i][0];
            int total=classes[i][1];
            double delta=(double)(pass+1)/(total+1)-(double)(pass)/(total);
            pq.push({delta,{pass,total}});
        }
        
        while(extraStudents--){
            int pass=pq.top().second.first;
            int total=pq.top().second.second;
            pass++;
            total++;
            double newdelta=(double)(pass+1)/(total+1)-(double)(pass)/(total);
            pq.pop();
                pq.push({newdelta,{pass,total}});
        }
        double avg=0;
        while(!pq.empty()){
            avg+=(double)(pq.top().second.first)/(pq.top().second.second);
            pq.pop();
        }
        return avg/n;}
};