class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1,ans=0;
        while(i<=j){
            while(i<tokens.size() and power>=tokens[i]){power-=tokens[i++];ans++;}
            if(ans and j-i>1){ans--;power+=tokens[j--];}
            else{break;}
        }
        return ans;
    }
};