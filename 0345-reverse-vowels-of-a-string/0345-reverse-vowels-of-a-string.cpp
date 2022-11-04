class Solution {
public:
    bool isvowel(char c){
     return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'
            || c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';   
    }
    string reverseVowels(string s) {
    
    int start = 0, end = s.size() - 1;
        while(start < end){
            while(start < end && !isvowel(s[start])) start++;
            while(start < end && !isvowel(s[end])) end--;
            swap(s[start],s[end]);
            start++;end--;
        }
        return s;
    
        
    }
};