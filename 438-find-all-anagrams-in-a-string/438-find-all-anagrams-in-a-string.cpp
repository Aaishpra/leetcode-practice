class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        int i=0, j=0;
        for(char c:p){
            mp[c]++;
        }
        int cnt=mp.size();
        int n=s.size();
        int k=p.size();
        vector<int> ans;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) cnt--;
            }
            //if(j-i+1<k) j++;
            if(j-i+1==k){
                if(cnt==0) ans.push_back(i);
                if(mp.find(s[i])!=mp.end()){mp[s[i]]++;
                if(mp[s[i]]==1) cnt++;}
                i++;}
                j++;
            
        }
        return ans;
    }
};