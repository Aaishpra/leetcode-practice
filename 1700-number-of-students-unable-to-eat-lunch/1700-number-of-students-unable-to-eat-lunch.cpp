class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& sand) {
        
        stack<int> st;
        queue<int> q;
       
        reverse(sand.begin(),sand.end());
        for(int i:sand) st.push(i);
        
        for(int i:stu) q.push(i);
        
        int cnt=0;
        while(!st.empty()){
            if(q.front()==st.top()){
                q.pop();
                st.pop();
                cnt=0;
            }
            else{
            if(cnt==q.size()){
                return cnt;
            }
                int val=q.front();
                q.pop();
                q.push(val);
                cnt++;
            }
        }
        return 0;
    }
};