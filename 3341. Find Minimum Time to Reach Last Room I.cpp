// T.C: O(n*mlog(n*m)
// S.C: O(n*m)
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for(auto& dir: directions){
                int x = i + dir[0];
                int y = j + dir[1];
                if(x >= 0 && x < n &&  y >= 0 && y < m){
                    int w = 1 + max(d, moveTime[x][y]);
                    if(w < result[x][y]){
                        result[x][y] = w;
                        pq.push({w, {x, y}});
                    }
                }
            }

        }

        return result[n-1][m-1];
    }
};
