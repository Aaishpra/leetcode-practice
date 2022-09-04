class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        stack<int> s;
        vector<int> v;
        
        for (int i=0; i<A.size(); i++) {
                        
            while (!s.empty() && s.top() < A[i]) {
                v.push_back(s.top() * s.top());
                s.pop();
            }
            
            if (A[i] < 0) s.push(abs(A[i]));
            else v.push_back(A[i]*A[i]);

        }

        while (!s.empty()) {
            v.push_back(s.top()*s.top());
            s.pop();
        }
        
        return v;

    }
};