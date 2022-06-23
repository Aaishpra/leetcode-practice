class Solution {

public:

    static bool cmp(vector<int> a, vector<int> b)

    {

        if(a[1]==b[1]) return a[0]<b[0];

        return a[1]<b[1];

    }

    

    int scheduleCourse(vector<vector<int>>& a) {

        int n=a.size();

        int time=0, cnt=0;

        sort(a.begin(),a.end(),cmp);

        priority_queue<int> pq;

        for(int i=0;i<n;i++)

        {

            if(time+a[i][0]<=a[i][1])

            {

                time+=a[i][0];

                pq.push(a[i][0]);

                cnt++;

            }

            else if(!pq.empty() and pq.top()>a[i][0])

            {

                time+=a[i][0]-pq.top();

                pq.pop();

                pq.push(a[i][0]);

            }

        }

        return cnt;

    }

};