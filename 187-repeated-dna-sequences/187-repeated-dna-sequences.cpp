class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int i=0,j=0;
        
       
        unordered_map<string,int> mp;
        string word;
        while(j<s.size()){
            word+=s[j];
            if(j-i+1<10){
                j++;
            }
            else{
                mp[word]++;
                word=word.substr(1);
                i++;
                j++;
            }
        }
        vector<string> ans;
        
        for(auto m:mp){
            if(m.second>1)
                ans.push_back(m.first);
        }
        return ans;
    }
};