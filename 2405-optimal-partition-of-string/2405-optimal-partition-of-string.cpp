class Solution {
public:
    int partitionString(string s) {
        int cnt=1;
        int i=0;
        set<char> st;
       for(int i=0;i<s.size();i++){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
            }
           else{
               st.clear();
               cnt++;
               st.insert(s[i]);
           }
        }
        
        return cnt;
    }
};