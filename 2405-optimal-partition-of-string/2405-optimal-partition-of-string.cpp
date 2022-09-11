class Solution {
public:
    int partitionString(string s) {
        int cnt=0;
       int i=0;
        set<char> st;
        while(i<s.size()){
            while(i<s.size() and st.find(s[i])==st.end()){
                st.insert(s[i]);
                i++;
            }
            st.clear(),cnt++;
        }
        
        return cnt;
    }
};