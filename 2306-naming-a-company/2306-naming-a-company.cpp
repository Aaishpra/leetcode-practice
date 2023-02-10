class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
    vector<unordered_set<string>> st(26);
        for(auto i:ideas){
            st[i[0]-'a'].insert(i.substr(1));
        }
        
         long long ans=0;
        for (int i = 0; i < 25; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                unordered_set<string> s1=st[i],s2=st[j];
                int count=0;
                for(string a:s1){
                    count+=s2.count(a);
                }
                ans+=(s1.size()-count)*(s2.size()-count)*2;
            }
        }
        return ans;
    }
};