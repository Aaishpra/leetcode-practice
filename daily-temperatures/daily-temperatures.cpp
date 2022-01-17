class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //Stack Next Greater element to right
      int n=temperatures.size();
        vector<int> res;
     stack<pair<int,int>> s;
        for(int i=n-1;i>=0;i--){
            if(s.size()==0) res.push_back(0);
            else if(s.size()!=0 and s.top().first>temperatures[i]) res.push_back(s.top().second-i);
             else if(s.size()!=0 and s.top().first<=temperatures[i]){
                 while(s.size()>0 and s.top().first<=temperatures[i]){ s.pop();
                                                               }
                 if(s.size()==0) res.push_back(0);
                 else{res.push_back(s.top().second-i);
                     }
                 
             }
            s.push({temperatures[i],i});
        }
        reverse(res.begin(),res.end());     
    
    return res;}
};