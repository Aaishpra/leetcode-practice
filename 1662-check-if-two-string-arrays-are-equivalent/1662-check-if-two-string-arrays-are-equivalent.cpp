class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a;
        string b;
        
        for(int i=0;i<word1.size();i++){
            for(char c:word1[i]){
                a+=c;
            }
        }
         for(int i=0;i<word2.size();i++){
            for(char c:word2[i]){
                b+=c;
            }
        }
        
        return a==b;
    }
};