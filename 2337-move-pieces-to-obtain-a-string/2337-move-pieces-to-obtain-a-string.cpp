class Solution {
public:
    bool relativeOrder(string a,string b){
        string s1,s2;
        for(char c:a) if(c!='_') s1.push_back(c);
        for(char c:b) if(c!='_') s2.push_back(c);
        return s1==s2;
    }
    bool canChange(string start, string target) {
        if(!relativeOrder(start,target)) return false;
        vector<int> l1,l2,r1,r2;
        
        for(int i=0;i<start.size();i++)
        {
            if(start[i]=='L') l1.push_back(i);
            if(start[i]=='R') r1.push_back(i);
            if(target[i]=='L') l2.push_back(i);
            if(target[i]=='R')r2.push_back(i);
        }
        
        for(int i=0;i<l1.size();i++)if(l1[i]<l2[i])return false;
        for(int i=0;i<r1.size();i++)if(r1[i]>r2[i])return false;
        return true;
    }
};