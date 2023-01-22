class Solution {
public:
    vector<string> res;
    bool isValid(string str,int i){
        if((i==0 and str>="0" and str<="9") or (i==1 and str>="10" and str<="99") or (i==2 and str>="100" and str<="255")){
            return true;}
        return false;
    }
    void solve(int idx,string& ip,vector<string> &op){
        if(idx>=ip.size() and op.size()==4){
            res.push_back(op[0]+'.' + op[1]+'.'+op[2]+'.'+op[3]);
            return;
        }
        
        for(int i=0;i<3;i++){
         if(idx+i<=ip.size()-1){
            if(isValid(ip.substr(idx,i+1),i))
            {
                op.push_back(ip.substr(idx,i+1));
                solve(idx+i+1,ip,op);
                op.pop_back();
            }
             }
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> op;
        solve(0,s,op);
        return res;
    }
};