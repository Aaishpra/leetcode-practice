class Solution {
public:
    bool isItPossible(string word1, string word2) {
     unordered_map<char,int> mp,mp1;
        for(auto c:word1) mp[c]++;
        for(auto c:word2) mp1[c]++;
        
        for(auto m:mp){
            for(auto m1:mp1){
                char c=m.first;
                char c1=m1.first;
                unordered_map<char,int>n1=mp,n2=mp1;
                n2[c]++;  
                n1[c1]++; 

                n2[c1]--; 
                n1[c]--;
                
                
                if(n2[c1]==0)
                    n2.erase(c1);
                
                if(n1[c]==0)
                    n1.erase(c);
                
                if(n1.size()==n2.size())
                    return true;
            }
        }
        return false;
    }
};