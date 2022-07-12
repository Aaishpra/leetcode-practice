class Solution {
public:
    string greatestLetter(string s) {
        char mx='0';
        for(char c:s){
            if(islower(c) and s.find(toupper(c)) != std::string::npos){
                if(toupper(c)>mx){
                    mx=toupper(c);
                }
                
            }
            else if(isupper(c) and s.find(tolower(c)) != std::string::npos){
                if(c>mx){
                    mx=c;
                }
               
            }
        }
        string res(1,mx);
        return res=="0"?"":res;
    }
};