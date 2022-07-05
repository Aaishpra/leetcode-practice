class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tempratures) {
  int n=tempratures.size();      
        vector<int> res;
        stack<pair<int,int>> s;
        for(int i=n-1;i>=0;i--){
            if(s.size()==0) res.push_back(0);
            else if(s.top().first>0 and s.top().first>tempratures[i]) res.push_back(s.top().second-i);
            else if(s.top().first>0 and s.top().first<=tempratures[i]){
                while(s.size()>0 and s.top().first<=tempratures[i]) s.pop();
                if(s.size()==0) res.push_back(0);
                else res.push_back(s.top().second-i);
            }  
            s.push({tempratures[i],i});
        }
        reverse(res.begin(),res.end());
        return res;
    }
};