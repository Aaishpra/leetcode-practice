class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
     unordered_map<char , int> map;
        for(char m:magazine) ++map[m];
        for(char r:ransomNote){
            if(--map[r]<0) return false;
        }
        return true;
    }
};