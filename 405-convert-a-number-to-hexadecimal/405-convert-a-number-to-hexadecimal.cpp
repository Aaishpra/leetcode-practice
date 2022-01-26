class Solution {
public:
    string toHex(int num) {
     unsigned int ournum=num;
        char ar[17]="0123456789abcdef";
        string ans="";
        do{
            ans+=ar[ournum%16];
            ournum/=16;
        }while(ournum);
        return {ans.rbegin(),ans.rend()};
    }
};