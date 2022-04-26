class Solution {
public:
    string mergeAlternately(string w1, string w2) {
     
        string s="";
        int i=0,j=0;
        
        while(i<w1.length() && j<w2.length())
            s=s+w1[i++]+w2[j++];
        
        while(i<w1.length())
            s+=w1[i++];
        
        while(j<w2.length())
            s+=w2[j++];
        
        return s;
    }
};