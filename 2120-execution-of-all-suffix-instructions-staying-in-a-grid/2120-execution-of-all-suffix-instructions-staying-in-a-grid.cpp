static int X[4] = {0,0,-1,1};
static int Y[4] = {1,-1,0,0};
static unordered_map<char, int> mp = {
    {'R', 0},
    {'L', 1},
    {'U', 2},
    {'D', 3}
};

class Solution {
public:
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m=s.size();
     vector<int> ans(m);
        
        for(int i=0;i<m;i++){
            int cnt=0;
            
            int x=startPos[0];
            int y=startPos[1];
          for(int j=i;j<m;j++){
               x+=X[mp[s[j]]];
               y+=Y[mp[s[j]]];
                if(x>=0 and x<n and y>=0 and y<n){
                    cnt++;
                   // j++;
                }
                else {
                    break;
                }
            }
            ans[i]=cnt;
        }
        return ans;
    }
};