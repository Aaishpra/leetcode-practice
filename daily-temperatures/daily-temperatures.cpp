class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        vector<int> v;
        for(int i=temperatures.size()-1;i>=0;i--){
            if(s.size()==0){v.push_back(0);}
            if(s.size()!=0 && s.top().first>temperatures[i])
            {v.push_back(s.top().second-i);}
            else if(s.size()!=0 && s.top().first<=temperatures[i]){
                while(s.size()!=0 && s.top().first<=temperatures[i]){
                    s.pop();
                }
                if(s.size()==0){v.push_back(0);}
                else {v.push_back(s.top().second-i);}
            }
            s.push({temperatures[i],i});
        }
       
        reverse(v.begin(),v.end());
         return v;
    }
// vector<int> dailyTemperatures(vector<int>& T)
// {
// stack<pair<int,int>>st;
// vector<int> v;
// int i;
// for( i=T.size()-1;i>=0;i--)
// {
// if(st.size()==0)
// {
// v.push_back(0);
// }
// else if(st.size()!=0 && st.top().first>T[i])
// {
// v.push_back(st.top().second-i);
// }
// else if(st.size()!= 0 && st.top().first<=T[i])
// {
// while(st.size()!=0 && st.top().first<=T[i])
// {
// st.pop();
// }
// if(st.size()==0)
// {
// v.push_back(0);
// }
// else
// {
// v.push_back(st.top().second-i);
// }
// }
// st.push({T[i],i});
// }

//     reverse(v.begin(),v.end());
//     return v;
// }
};