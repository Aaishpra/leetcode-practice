class Solution {
public:
    
    vector<int> solve(string s,unordered_map<string,vector<int>> &dp){
         vector<int> res;
        
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='-' or c=='+' or c=='*'){
                string s1=s.substr(0,i);
                string s2=s.substr(i+1);
                
                vector<int> r1,r2;
                
                if(dp.find(s1)!=dp.end()){
                    r1=dp[s1];
                }
                else r1=solve(s1,dp);
                
                 if(dp.find(s2)!=dp.end()){
                    r2=dp[s2];
                }
                else r2=solve(s2,dp);
                
                
                for(int x:r1){
                    for(int y:r2){
                        if(c=='-'){
                            res.push_back(x-y);
                        }
                        else if(c=='+'){
                            res.push_back(x+y);
                        }
                        else if(c=='*'){
                            res.push_back(x*y);
                        }
                    }
                }
            }
        }
        if(res.size()==0)
            res.push_back(stoi(s));
        return dp[s]=res;
    }
    vector<int> diffWaysToCompute(string s) {
     unordered_map<string,vector<int>> dp;
        return solve(s,dp);
    }
};