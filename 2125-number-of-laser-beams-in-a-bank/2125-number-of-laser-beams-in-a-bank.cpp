class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       int count=0,prev=0,sum=0;
       
         for(string s: bank) {
        count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                count++;
            }}
            if(count){
                sum+=prev*count;
                prev=count;
            }
        }
         
        return sum;
    }
};