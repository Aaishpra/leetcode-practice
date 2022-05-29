class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> mp;
        for(char c:s)
            mp[c]++;
        int count=0;
        bool flag=true;
        while(flag){
            for(char c:target){
                mp[c]--;
                if(mp[c]<0) flag=false;
            }
            if(flag==true)  count++;
        }
        return count;
    }
};