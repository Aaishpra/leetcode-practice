class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
     
        vector<int> res;
        
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='-' or c=='+' or c=='*'){
                string s1=s.substr(0,i);
                string s2=s.substr(i+1);
                vector<int> r1=diffWaysToCompute(s1);
                vector<int> r2=diffWaysToCompute(s2);
                
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
        return res;
    }
};