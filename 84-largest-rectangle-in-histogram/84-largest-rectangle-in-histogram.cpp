class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left, right;
        stack<pair<int, int>> s1,s2;
         int n=heights.size();
        // Next smaller to left
        for(int i=0;i<n;i++){
            if(s1.size()==0){
                left.push_back(-1);
            }
            else if(s1.size()>0 && s1.top().first< heights[i]){
                left.push_back(s1.top().second);
            }
            else if(s1.size()>0 && s1.top().first>=heights[i]){
                while(s1.size()>0 && s1.top().first>= heights[i]){
                s1.pop();
            }
                if(s1.size()==0) {
                    left.push_back(-1);
                }
                else {
                    left.push_back(s1.top().second);
                }
            }
            s1.push({heights[i],i});
        }
       
        // Next smaller to right
         for(int i=heights.size()-1;i>=0;i--){
             if(s2.size()==0){
                 right.push_back(n);
             }
             else if( s2. size()>0 && s2.top().first< heights[i]){
                 right.push_back(s2.top().second);
             } 
              else if(s2.size()>0 && s2.top().first>=heights[i]){
                while(s2.size()>0 && s2.top().first>= heights[i]){
                s2.pop();
            }
                if(s2.size()==0) {
                    right.push_back(n);
                }
                else {
                right.push_back(s2.top().second);
                }
            }
            s2.push({heights[i],i});
         }
         reverse(right.begin(),right.end()); //Reverse the right in the end
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx, (right[i]-left[i]-1)*heights[i]);
        }
        return mx;
    }
};